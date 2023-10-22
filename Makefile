NAME = fdf
CC = cc -Wall -Wextra -Werror -g3
SRC = src/read_file.c src/main.c
INCLUDE = libft/libft.a

all: $(SRC)
	@make -C libft/ all
	$(CC) $(SRC) -o $(NAME) $(INCLUDE)

clean:
	@make -C libft/ clean

fclean:
	@make -C libft/ fclean

re:
	fclean all