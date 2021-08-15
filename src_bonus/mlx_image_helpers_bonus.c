/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:14:56 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/12 13:14:56 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	generate_mlx_image(t_game_state *state,
		t_image_data *data, int width, int height)
{
	data->img_ptr = mlx_new_image(state->mlx.mlx_ptr, width, height);
	if (data->img_ptr == NULL)
		quit_with_error(errno, state);
	data->img = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_size, &data->endian);
	if (data->img == NULL)
		quit_with_error(errno, state);
	data->width = width;
	data->height = height;
	data->mem_width = data->line_size / (data->bits_per_pixel / 8);
}
