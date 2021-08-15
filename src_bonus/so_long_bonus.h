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

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
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

typedef struct s_mlx				t_mlx;
typedef struct s_game_state			t_game_state;
typedef enum e_directions			t_directions;
typedef struct s_map_textures		t_map_textures;
typedef struct s_tile				t_tile;
typedef struct s_map				t_map;
typedef struct s_player				t_player;
typedef struct s_img_data			t_image_data;
typedef struct s_animated_sprite	t_animated_sprite;

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

struct s_animated_sprite {
	t_list	*current_image;
	t_list	*images;
	void	*img_ptr;
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
	t_tile	*player_current;
	t_tile	*collectible_current;
	t_tile	*exit_current;
	t_tile	player0;
	t_tile	player1;
	t_tile	player2;
	t_tile	player3;
	t_tile	collectible0;
	t_tile	collectible1;
	t_tile	collectible2;
	t_tile	exit0;
	t_tile	exit1;
	t_tile	exit2;
	t_tile	exit3;
};

struct s_map {
	int				width;
	int				height;
	t_image_data	img_data;
	t_image_data	sprites_data;
};

struct s_player {
	t_animated_sprite	img_data;
	t_image_data		sprites_data;
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
	int				game_finished;
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
void			render_map(t_game_state *state);
void			init_map(t_game_state *state);
int				loop_handler(t_game_state *state);
void			change_sprite_frames(t_game_state *state);
void			init_player(t_game_state *state);
void			init_exit(t_game_state *state);
void			init_collectibles(t_game_state *state);
void			print_movements(t_game_state *state);
void			prepare_next_frame(t_game_state *state);

#endif
