NAME = so_long

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all -s \
		   --track-origins=yes

SRC_DIR = src
OBJ_DIR = obj
SRC_BONUS_DIR = src_bonus

HEADERS = src/so_long.h
BONUS_HEADERS = src_bonus/so_long_bonus.h

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
			output.c				\
			cleaning.c				\
			wall_helpers.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRC_BONUS_FILES = main_bonus.c				\
			error_handlers_bonus.c			\
			arg_validator_bonus.c			\
			map_parser_bonus.c				\
			arg_parser_bonus.c				\
			event_handlers_bonus.c			\
			movement_bonus.c				\
			mlx_sprite_helpers_bonus.c		\
			mlx_image_helpers_bonus.c		\
			map_renderer_bonus.c		 	\
			map_generator_bonus.c			\
			map_drawer_bonus.c				\
			wall_helpers_bonus.c			\
			output_bonus.c					\
			animated_sprites_bonus.c		\
			animated_sprite_helpers_bonus.c \
			rng_bonus.c						\
			cleaning_bonus.c				\
			enemy_bonus.c

SRC_BONUS = $(addprefix $(SRC_BONUS_DIR)/, $(SRC_BONUS_FILES))
OBJ_BONUS = $(SRC_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS = -Wall -Werror -Wextra
CC = clang
LIBFLAGS = -lft -lXext -lX11 -lmlx

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(OBJ) -L$(LIBFT_DIR) -L$(MLX_DIR) $(LIBFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c -I$(INCLUDE_DIR) -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_BONUS_DIR)/%.c $(BONUS_HEADERS)
	$(CC) $(CFLAGS) -c -I$(INCLUDE_DIR) -o $@ $<

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

bonus: $(OBJ_DIR) $(LIBFT) $(MLX) $(OBJ_BONUS)
	touch bonus
	$(CC) $(OBJ_BONUS) -L$(LIBFT_DIR) -L$(MLX_DIR) $(LIBFLAGS) -o $(NAME)


run: bonus
	#$(VALGRIND) ./$(NAME) files/bad_map.ber
	#$(VALGRIND) ./$(NAME) files/no_player.ber
	#$(VALGRIND) ./$(NAME) files/no_exit.ber
	#$(VALGRIND) ./$(NAME) files/no_collectible.ber
	#$(VALGRIND) ./$(NAME) files/not_rectangular.ber
	$(VALGRIND) ./$(NAME) files/simple.ber
	#$(VALGRIND) ./$(NAME) files/multiple_enemies.ber

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)
	$(RM) bonus

fclean: clean
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
