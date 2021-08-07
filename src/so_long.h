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

struct s_game_state {
	char	*program_name;
	char	*map_filename;
	int		map_fd;
	int		map_width;
	int		map_height;
	t_list	*map_rows;
	char	*map;
	size_t	player_pos;
	size_t	movement_count;
	size_t	collected_collectibles;
	size_t	total_collectibles;
};

struct s_window {
	void	*mlx_ptr;
	void	*win;
};

# define ERR_SIZE 2

enum e_errors {
	ERR_INVALID_MAP,
	ERR_MULTIPLAYER,
};

enum e_directions {
	DIRECTION_UP,
	DIRECTION_DOWN,
	DIRECTION_LEFT,
	DIRECTION_RIGHT,
};

typedef struct s_window		t_window;
typedef struct s_game_state	t_game_state;
typedef enum e_directions	t_directions;

void			quit_with_error(int my_errno, t_game_state *t_state);
int				validate_args(int argc, char *argv[]);
t_game_state	*parse_arg(char *args[]);
void			get_map(t_game_state *state);
void			generate_map(t_game_state *state);
void			clear(t_game_state *state);
int				key_handler(int keycode, void *param);
int				destroy_handler(void);
void			move(t_directions direction, t_game_state *state);

#endif
