# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tafujise <tafujise@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 12:42:52 by tafujise          #+#    #+#              #
#    Updated: 2025/10/30 15:33:08 by tafujise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := push_swap

SRCDIR := ./srcs
SRCS := push_swap.c

HEADDIR := ./includes
HEADERS := $(HEADDIR)/ft_printf.h

OBJS := $(addprefix $(SRCDIR)/, $(SRCS:.c=.o))
 
LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a

CC := cc

CCFLAGS := -Wall -Wextra -Werror -I$(HEADDIR) -I$(LIBFT_DIR)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) &(LIBFT)

$(NAME): $(OBJS)


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