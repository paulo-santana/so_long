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
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define SO_LONG_H

enum e_errors
{
	ERR_INVALID_ARGS = EINVAL,
	ERR_FILE_OPEN,
};

struct s_game_info {
	char	*program_name;
	char	*map_filename;
};

struct s_window {
	void	*mlx_ptr;
	void	*win_ptr;
};

typedef struct s_window		t_window;
typedef struct s_game_info	t_game_info;

void	handle_error();
int		validate_args(int argc, char *argv[]);

#endif
