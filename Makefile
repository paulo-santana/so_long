NAME = so_long

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

VALGRIND = valgrind --leak-check=full -q

SRC_DIR = src
OBJ_DIR = obj

HEADERS = src/so_long.h

INCLUDE_DIR = includes

SRC_FILES = main.c					\
			error_handlers.c		\
			arg_validator.c			\
			map_parser.c			\
			arg_parser.c			\
			event_handlers.c		\
			movement.c				\
			mlx_sprite_helpers.c	\
			mlx_image_helpers.c		\
			map_renderer.c 			\
			map_generator.c			\
			map_drawer.c			\
			wall_helpers.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRC_BONUS_FILES = main.c \
			error_handlers.c		\
			arg_validator.c			\
			map_parser.c			\
			arg_parser.c			\
			event_handlers.c		\
			movement.c				\
			mlx_sprite_helpers.c	\
			mlx_image_helpers.c		\
			map_renderer.c 			\
			map_generator.c			\
			map_drawer.c			\
			wall_helpers.c

SRC_BONUS = $(addprefix $(SRC_DIR)/, $(SRC_BONUS_FILES))
OBJ_BONUS = $(SRC_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS = -g3 -Wall -Werror -Wextra
CC = clang $(CFLAGS)
LIBFLAGS = -lft -lXext -lX11 -lmlx 

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC)  $(OBJ) -L$(LIBFT_DIR) -L$(MLX_DIR) $(LIBFLAGS) -o $(NAME)
	cp $(NAME) a.out #for debugging

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p obj
	$(CC) -c -I$(INCLUDE_DIR) -o $@ $<

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

bonus: $(LIBFT) $(MLX) $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -L$(LIBFT_DIR) -L$(MLX_DIR) $(LIBFLAGS) -o $(NAME)


run: all
	$(VALGRIND) ./$(NAME) files/bad_map.ber || \
	$(VALGRIND) ./$(NAME) files/no_player.ber || \
	$(VALGRIND) ./$(NAME) files/no_exit.ber || \
	$(VALGRIND) ./$(NAME) files/no_collectible.ber || \
	$(VALGRIND) ./$(NAME) files/not_rectangular.ber || \
	$(VALGRIND) ./$(NAME) files/simple.ber

clean:
	$(RM) $(OBJ)
	$(RM) vgcore*

fclean: clean
	@echo cleaning minilibx
	@make -C $(MLX_DIR) clean
	@echo done!
	@echo cleaning libft...
	@make -C $(LIBFT_DIR) fclean
	@echo done!
	$(RM) $(NAME)
	$(RM) a.out

re: fclean all

.PHONY: $(LIBFT)
