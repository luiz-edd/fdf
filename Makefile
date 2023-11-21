NAME = fdf
CC = cc -Wall -Wextra -Werror -g -O0 -Wunreachable-code
LEAKS = valgrind --leak-check=full --show-leak-kinds=all --gen-suppressions=all --suppressions=./libraries/MLX42/suppress.sup

LIBMLX = ./lib/MLX42

HEADER = -I ./lib/libft/src -I $(LIBMLX)/include
LIBFT = lib/libft/libft.a
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

PATH_LIBFT = lib/libft/
PATH_TO_SRC = src/
PATH_TO_OBJ = obj/

SRC = read_file.c main.c draw.c color.c rotation.c positioning.c control.c
OBJ = $(SRC:.c=.o)

SRC_PATH = $(addprefix $(PATH_TO_SRC), $(SRC))
OBJ_PATH = $(addprefix $(PATH_TO_OBJ), $(OBJ))

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJ_PATH)
	$(CC) $(OBJ_PATH) $(LIBFT) $(LIBS) $(HEADER) -o $(NAME)

$(PATH_TO_OBJ)%.o: $(PATH_TO_SRC)%.c
	mkdir -p obj
	make -C $(PATH_LIBFT) all	
	$(CC) $< -o $@ -c $(HEADER) 

clean:
	@rm -rf obj
	@rm -rf $(LIBMLX)/build
	@make -C $(PATH_LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(PATH_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re