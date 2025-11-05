# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 12:42:52 by tafujise          #+#    #+#              #
#    Updated: 2025/11/05 19:53:28 by tafujise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
BONUS_NAME := checker

SRCDIR := srcs
SRCS := check_error.c\
		free.c\
		init_stack.c\
		limits.c\
		list.c\
		main.c\
		parse_args.c\
		print_error.c\
		utils.c\
		sort.c\
		instructions.c\

SRCS_BONUS := checker.c\
			check_error.c\
			free.c\
			init_stack.c\
			limits.c\
			list.c\
			parse_args.c\
			print_error.c\
			utils.c\
			instructions.c\
			sort_for_checker.c\

HEADDIR := includes
HEADERS := $(HEADDIR)/ft_printf.h

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

OBJS := $(addprefix $(SRCDIR)/, $(SRCS:.c=.o))
OBJS_BONUS := $(addprefix $(SRCDIR)/, $(SRCS_BONUS:.c=.o))

CC := cc

CCFLAGS := -Wall -Wextra -Werror -I$(HEADDIR) -I$(LIBFT_DIR)

all: $(NAME)

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

.PHONY: all clean fclean re bonus
