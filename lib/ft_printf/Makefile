NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SOURCE = ft_printf.c ft_checkformat.c ft_putstr.c ft_putnbr.c ft_putunsigned.c ft_putchar.c ft_printhex_u.c ft_printhex_l.c ft_printpointer.c check_ft_checkformat.c
OBJ = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ft_printf.h
		ar rcs $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)
		rm -f $(OBJ)

re:	fclean all

.PHONY: clean fclean
