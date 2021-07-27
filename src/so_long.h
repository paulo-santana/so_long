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

struct s_game_info {
	char	*program_name;
	char	*map_filename;
};

struct s_window {
	void	*mlx_ptr;
	void	*win_ptr;
};

enum e_errors {
	ERR_INVALID_MAP,
};

typedef struct s_window		t_window;
typedef struct s_game_info	t_game_info;

void		quit_with_error(int err);
int			validate_args(int argc, char *argv[]);
t_game_info	*parse_arg(char *args[]);
void		get_map(t_game_info *game_info);

#endif
