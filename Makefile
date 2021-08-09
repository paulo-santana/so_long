NAME = so_long

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

VALGRIND = valgrind --leak-check=full -q

SRC_DIR = src
OBJ_DIR = obj

UTILS = src/utils.c

HEADERS = src/so_long.h \
		  src/utils.h

INCLUDE_DIR = includes

SRC_FILES = main.c					\
			error_handlers.c		\
			validation.c			\
			map_parser.c			\
			arg_parser.c			\
			event_handlers.c		\
			movement.c				\
			map_renderer.c 			\
			map_generator.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS = -g -Wall -Werror -Wextra
CC = clang $(CFLAGS)
LIBFLAGS = -lft -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(UTILS) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -L$(MLX_DIR) $(LIBFLAGS)
	cp $(NAME) a.out #for debugging

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p obj
	$(CC) -O3 -c $(CFLAGS) -I$(INCLUDE_DIR) -o $@ $<

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

run: all
	$(VALGRIND) ./$(NAME) files/multiple_collectibles.ber

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
