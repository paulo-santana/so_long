NAME = so_long

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = main.c					\
			error_handling.c		\
			validation.c			\
			map_parser.c			\
			arg_parser.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	clang $(OBJ) -O3 -g -o $(NAME) -L./libft -lft -L./minilibx-linux -lmlx -lXext -lX11 -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj
	clang -O3 -g -c -Wall -Werror -Wextra -o $@ $<

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

run: all
	./$(NAME) files/simple.ber

clean:
	$(RM) $(OBJ)

fclean: clean
	@echo cleaning minilibx
	@make -C $(MLX_DIR) clean
	@echo done!
	@echo cleaning libft...
	@make -C $(LIBFT_DIR) fclean
	@echo done!
	$(RM) $(NAME)

re: fclean all

.PHONY: $(LIBFT)
