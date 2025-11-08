# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 12:42:52 by tafujise          #+#    #+#              #
#    Updated: 2025/11/08 23:03:18 by tafujise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=push_swap
BONUS_NAME:=checker

SRCDIR:=srcs
SRCS:=main.c\
		common/check_error.c\
		common/free.c\
		common/init.c\
		common/limits.c\
		common/parse_args.c\
		common/print_error.c\
		common/utils.c\
		stack/list.c\
		stack/operations_1.c\
		stack/operations_2.c\
		algo/sort.c\
		algo/calc_cost.c\
		algo/calc_operations.c\
		algo/small_stack_sort.c\
# 		test.c\
		

SRCS_BONUS:=main_bonus.c\
			common/check_error.c\
			common/free.c\
			common/init.c\
			common/limits.c\
			common/parse_args.c\
			common/print_error.c\
			common/utils.c\
			stack/list.c\
			stack/operations_1.c\
			stack/operations_2.c\
			checker/apply.c\
			checker/print_result.c\
			checker/get_next_line.c\
# 			test.c\

HEADDIR:=includes
HEADERS:=$(HEADDIR)/ft_printf.h

LIBFT_DIR:=libft
LIBFT:=$(LIBFT_DIR)/libft.a

OBJS:=$(addprefix $(SRCDIR)/, $(SRCS:.c=.o))
OBJS_BONUS:=$(addprefix $(SRCDIR)/, $(SRCS_BONUS:.c=.o))

CC:=cc

CCFLAGS:=-Wall -Wextra -Werror -I$(HEADDIR) -I$(LIBFT_DIR)

DEBUG_FLAGS:=-g -O0

all:$(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT)

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CCFLAGS) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS) $(LIBFT)
	$(CC) -o $(BONUS_NAME) $(OBJS_BONUS) $(LIBFT)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

debug: CCFLAGS += $(DEBUG_FLAGS)
debug:
	$(MAKE) fclean
	$(MAKE) -C $(LIBFT_DIR) CCFLAGS="$(CCFLAGS)" all
	$(MAKE) CCFLAGS="$(CCFLAGS)" all

.PHONY: all clean fclean re bonus
