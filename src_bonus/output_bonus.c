/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:17:14 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/15 18:17:14 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_movements(t_game_state *state)
{
	char	*str;
	char	*moves;

	str = ft_calloc(100, 1);
	if (str == NULL)
		quit_with_error(errno, state);
	moves = ft_itoa(state->movement_count);
	if (moves == NULL)
		return (free(str));
	ft_strlcpy(str, "Moves: ", 100);
	ft_strlcat(str, moves, 100);
	mlx_put_image_to_window(state->mlx.mlx_ptr, state->mlx.window,
		state->cleaner.img_ptr, 0, 0);
	mlx_string_put(state->mlx.mlx_ptr, state->mlx.window, 15, 15, 0xff6700,
		str);
	free(str);
	free(moves);
}
