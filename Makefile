NAME = fdf
CC = cc -Wall -Wextra -Werror -g3 -Wunreachable-code -Ofast
LIBMLX = ./lib/MLX42

HEADER = -I libft/libft.a -I $(LIBMLX)/include
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -l 

PATH_TO_SRC = src/
PATH_TO_OBJ = obj/

SRC = read_file.c main.c
OBJ = $(SRC:.c=.o)

SRC_PATH = $(addprefix $(PATH_TO_SRC), $(SRC))
OBJ_PATH = $(addprefix $(PATH_TO_OBJ), $(OBJ))

all: $(NAME)

$(NAME): $(OBJ_PATH)
	$(CC) $(OBJ_PATH) $(LIBS) $(HEADER) -o $(NAME)

$(PATH_TO_OBJ)%.o: $(PATH_TO_SRC)%.c
	mkdir obj
	make -C libft/ all	
	$(CC) $< -o $@ -c $(HEADER)

clean:
	@rm -rf $(OBJ_PATH)
	@rm -rf $(LIBMLX)/build
	@make -C libft/ clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ fclean

re:
	fclean all