
NAME = push_swap.a

CC = cc

SRCS = libft/ft_isalnum.c libft/ft_atoi.c libft/ft_substr.c \
libft/ft_putendl_fd.c

OBJ = $(SRCS:.c=.o)

HEADER_DIR = .

HEADER = $(HEADER_DIR)/libft.h push_swap.h

CFLAGS = -Wall -Wextra -Werror -I$(HEADER_DIR)

RM = rm -f

AR = ar rcs

all : $(NAME)

$(NAME) : $(OBJ)
	${AR} $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re clean fclean all bonus
