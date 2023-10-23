NAME = fdf
CC = cc -Wall -Wextra -Werror -g3 -Wunreachable-code -Ofast
SRC = src/read_file.c src/main.c
HEADER = -I libft/libft.a -I ./lib/MLX42

all: libmlx $(NAME)


%.o: %.c
	@make -C libft/ all
	$(CC) $(SRC) -o $@ -c $< $(HEADER) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBS) $(HEADER) -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@make -C libft/ clean

fclean:
	@rm -rf $(NAME)
	@make -C libft/ fclean

re:
	fclean all