# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/29 22:04:51 by jschmitz          #+#    #+#              #
#    Updated: 2024/09/14 21:10:50 by jschmitz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

SRCS =	printf/ft_args_selector.c \
		printf/ft_printf.c \
		printf/ft_putchar_ptr.c \
		printf/ft_putstr_ptr.c\
		printf/ft_putnbr_hex_ptr.c \
		printf/ft_putnbr_ptr.c \
		printf/ft_putptr.c \
		printf/ft_unsigned_putnbr_ptr.c \
		libft/ft_substr.c \
		libft/ft_strlen.c \
		libft/ft_bzero.c \
		libft/ft_calloc.c \
		libft/ft_atoi.c \
		srcs/sorting_utils.c \
		srcs/parsing_utils.c \
		srcs/ft_atol.c \
		srcs/ft_sqrt_ps.c \
		srcs/create_stack.c \
		srcs/pick_algo.c \
		srcs/big_sort.c \
		srcs/allowed_moves.c \
		srcs/printing_instructions.c \
		srcs/combined_moves.c \
		srcs/second_sort.c \
		srcs/cost_utils.c \
		srcs/main.c

OBJ = $(SRCS:.c=.o)

HEADER_DIR = ./headerfiles

HEADER = $(HEADER_DIR)/libft.h $(HEADER_DIR)/push_swap.h

CFLAGS = -Wall -g3 -Wextra -Werror -I$(HEADER_DIR)

RM = rm -f

AR = ar rcs

all : $(NAME)

$(NAME) : $(OBJ)
	${CC} $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re clean fclean all
