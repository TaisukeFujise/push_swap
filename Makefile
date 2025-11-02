# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 12:42:52 by tafujise          #+#    #+#              #
#    Updated: 2025/11/02 23:17:53 by tafujise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := push_swap

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

HEADDIR := includes
HEADERS := $(HEADDIR)/ft_printf.h
 
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

OBJS := $(addprefix $(SRCDIR)/, $(SRCS:.c=.o))

CC := cc

CCFLAGS := -Wall -Wextra -Werror -I$(HEADDIR) -I$(LIBFT_DIR)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT)

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CCFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re