# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/29 22:04:51 by jschmitz          #+#    #+#              #
#    Updated: 2024/09/06 18:11:11 by jschmitz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

SRCS =	libft/ft_substr.c \
		libft/ft_strlen.c \
		libft/ft_atol.c \
		push_swap_files/push_swap.c \
		push_swap_files/create_stack.c \
		push_swap_files/ft_isalnumextended.c \
		push_swap_files/allowed_moves.c \
		push_swap_files/sorting_algorithm.c \
		push_swap_files/sort_helper_functions.c \
		push_swap_files/big_sort.c \
		push_swap_files/list_free.c

OBJ = $(SRCS:.c=.o)

HEADER_DIR = ./headerfiles

HEADER = $(HEADER_DIR)/libft.h $(HEADER_DIR)/push_swap.h

CFLAGS = -Wall -Wextra -Werror -I$(HEADER_DIR)

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
