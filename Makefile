
NAME = push_swap.a

CC = cc

SRCS = libft/ft_isalnum.c libft/ft_atoi.c libft/ft_substr.c \
libft/ft_putendl_fd.c 

OBJ = $(SRCS:.c=.o)

BONUS = ft_lstnew_bonus.c libft/ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJBONUS = $(BONUS:.c=.o)

HEADER_DIR = .

HEADER = $(HEADER_DIR)/libft.h

CFLAGS = -Wall -Wextra -Werror -I$(HEADER_DIR)

RM = rm -f

AR = ar rcs

all : $(NAME)

$(NAME) : $(OBJ)
	${AR} $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJBONUS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJBONUS)
	${AR} ${NAME} ${OBJBONUS}

.PHONY: re clean fclean all bonus
