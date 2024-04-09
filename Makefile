NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42
LIBFT := ./lib/libft
FT_PRINTF := ./lib/ft_printf

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT) -I $(FT_PRINTF)
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}
all: libmlx libft ft_printf $(NAME)

libft:
	@make -C $(LIBFT)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

ft_printf:
	@make -C $(FT_PRINTF)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): CFLAGS += -D BONUS=0
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@make clean -C $(LIBFT)
	@make clean -C $(FT_PRINTF)
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@make fclean -C $(LIBFT)
	@make fclean -C $(FT_PRINTF)
	@rm -rf $(NAME)

re: fclean all

bonus: CFLAGS += -D BONUS=1
bonus: libmlx libft ft_printf $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

.PHONY: all, clean, fclean, re, libmlx, libft, ft_printf