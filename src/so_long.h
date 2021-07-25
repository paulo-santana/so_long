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
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# define SO_LONG_H

# define ERR_INVALID_ARGS 1

struct s_x {
	void	*mlx_ptr;
	void	*win_ptr;
};

typedef struct s_x	t_param;

void	handle_error(int err);
int		validate_args(int argc, char *argv[]);

#endif
