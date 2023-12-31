NAME = fdf
BONUS_NAME = fdf_bonus
CC = cc -Wall -Wextra -Werror -g -O0 -Wunreachable-code
LEAKS = valgrind --leak-check=full --show-leak-kinds=all --gen-suppressions=all --suppressions=suppress.sup

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

SRC_BONUS = read_file_bonus.c main_bonus.c draw_bonus.c color_bonus.c rotation_bonus.c positioning_bonus.c control_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

PATH_TO_SRC_BONUS = src_bonus/
PATH_TO_OBJ_BONUS = obj_bonus/

SRC_BONUS_PATH = $(addprefix $(PATH_TO_SRC_BONUS), $(SRC_BONUS))
OBJ_BONUS_PATH = $(addprefix $(PATH_TO_OBJ_BONUS), $(OBJ_BONUS))

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJ_PATH)
	$(CC) $(OBJ_PATH) $(LIBFT) $(LIBS) $(HEADER) -o $(NAME)

$(PATH_TO_OBJ)%.o: $(PATH_TO_SRC)%.c
	mkdir -p obj
	make -C $(PATH_LIBFT) all	
	$(CC) $< -o $@ -c $(HEADER) 

bonus: libmlx $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_BONUS_PATH)
	$(CC) $(OBJ_BONUS_PATH) $(LIBFT) $(LIBS) $(HEADER) -o $(BONUS_NAME)

$(PATH_TO_OBJ_BONUS)%.o: $(PATH_TO_SRC_BONUS)%.c
	mkdir -p $(PATH_TO_OBJ_BONUS)
	make -C $(PATH_LIBFT) all	
	$(CC) $< -o $@ -c $(HEADER) 

clean:
	@rm -rf obj
	@rm -rf obj_bonus
	@rm -rf $(LIBMLX)/build
	@make -C $(PATH_LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS_NAME)
	@make -C $(PATH_LIBFT) fclean

re: fclean all

leak: all
	$(LEAKS) ./$(NAME) "test_maps/42.fdf" 

leak_bonus: all
	$(LEAKS) ./$(BONUS_NAME) "test_maps/42.fdf" 

normi:
	norminette src/* src_bonus/* lib/libft/src/*

.PHONY: all clean fclean re