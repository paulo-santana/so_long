/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 19:08:01 by psergio-          #+#    #+#             */
/*   Updated: 2021/07/24 19:08:01 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# define XK_MISCELLANY
# include <X11/keysymdef.h>
# include <X11/X.h>

# define ENTITY_WALL '#'
# define ENTITY_EXIT 'E'
# define ENTITY_FLOOR '~'
# define ENTITY_COLLECTIBLE 'C'
# define ENTITY_PLAYER 'P'

# define EXIT_SET "assets/xpm/exit.xpm"
# define ENEMY_SET "assets/xpm/slime.xpm"
# define PLAYER_SET "assets/xpm/player.xpm"
# define TILE_SET "assets/xpm/map.xpm"
# define SPRITE_TILE_SIZE 32
# define MAP_TILE_SIZE 48

typedef struct s_mlx			t_mlx;
typedef struct s_game_state		t_game_state;
typedef enum e_directions		t_directions;
typedef struct s_map_textures	t_map_textures;
typedef struct s_tile			t_tile;
typedef struct s_map			t_map;
typedef struct s_player			t_player;
typedef struct s_img_data		t_image_data;

struct s_mlx {
	void	*mlx_ptr;
	void	*window;
};

struct s_img_data {
	char	*img;
	void	*img_ptr;
	int		mem_width;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
};

struct s_tile {
	t_image_data	img_data;
	int				index;
};

struct s_map_textures {
	t_tile	floor;
	t_tile	wall_default;
	t_tile	wall_bottom;
	t_tile	wall_left;
	t_tile	wall_right;
	t_tile	wall_tl_corner;
	t_tile	wall_tr_corner;
	t_tile	wall_bl_corner;
	t_tile	wall_br_corner;
	t_tile	collectible;
	t_tile	exit;
	t_tile	player;
};

struct s_map {
	int				width;
	int				height;
	t_image_data	img_data;
	t_image_data	sprites_data;
};

struct s_player {
	t_image_data	img_data;
	t_image_data	sprites_data;
};

struct s_exit {
	t_image_data	sprites_data;
};

struct s_game_state {
	char			*program_name;
	char			*map_filename;
	int				map_fd;
	t_list			*map_rows;
	char			*map_mem;
	size_t			player_pos;
	size_t			movement_count;
	size_t			collected_collectibles;
	size_t			total_collectibles;
	size_t			exits;
	t_mlx			mlx;
	t_map_textures	textures;
	struct s_exit	exit;
	t_map			map;
	t_player		player;
};

# define ERR_SIZE 5

enum e_errors {
	ERR_INVALID_MAP,
	ERR_MULTIPLAYER,
	ERR_NO_PLAYER,
	ERR_NO_EXIT,
	ERR_NO_COLLECT,
};

enum e_directions {
	DIRECTION_UP,
	DIRECTION_DOWN,
	DIRECTION_LEFT,
	DIRECTION_RIGHT,
};

void			quit_with_error(int my_errno, t_game_state *t_state);
int				validate_args(int argc, char *argv[]);
t_game_state	*parse_arg(char *args[]);
void			get_map(t_game_state *state);
void			generate_map(t_game_state *state);
int				draw_map(t_game_state *state);
void			clear(t_game_state *state);
int				key_handler(int keycode, void *param);
int				destroy_handler(void);
int				handle_expose(t_game_state *state);
void			move(t_directions direction, t_game_state *state);
void			finish(void);

// mlx helpers
/**
 * Reads a sprite file and store its data insinde the `*image` struct.
 */
void			read_sprite(t_game_state *state, t_image_data *image,
					char *filename);

/**
 * Generates a mlx image and makes the pointer *state point to it
 */
void			generate_mlx_image(t_game_state *state,
					t_image_data *data, int width, int height);
void			copy_sprite_to_img(t_tile *tile, t_image_data *sprite);

// tile drawing functions
void			put_tile(t_tile *tile, t_game_state *state, int x, int y);
void			place_wall(t_game_state *state, int x, int y);
void			init_walls(t_game_state *state);

#endif
