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
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define ERR_SIZE 1

struct s_game_info {
	char	*program_name;
	char	*map_filename;
	int		map_fd;
	int		map_width;
	int		map_height;
	t_list	*map_rows;
	char	*map;
};

struct s_window {
	void	*mlx_ptr;
	void	*win;
};

enum e_errors {
	ERR_INVALID_MAP,
};

typedef struct s_window		t_window;
typedef struct s_game_info	t_game_info;

void		quit_with_error(int my_errno, t_game_info *t_game_info);
int			validate_args(int argc, char *argv[]);
t_game_info	*parse_arg(char *args[]);
void		get_map(t_game_info *game_info);
void		generate_map(t_game_info *game_info);
void		clear(t_game_info *game_info);

#endif
