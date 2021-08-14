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

#include "so_long.h"

void	read_sprite(t_game_state *state, t_image_data *image, char *filename)
{
	void	*img_ptr;
	void	*img_addr;
	int		width;
	int		height;

	img_ptr = mlx_xpm_file_to_image(
			state->mlx.mlx_ptr, filename, &width, &height);
	if (img_ptr == NULL)
		quit_with_error(errno, state);
	img_addr = mlx_get_data_addr(img_ptr, &image->bits_per_pixel,
			&image->line_size, &image->endian);
	if (img_addr == NULL)
		quit_with_error(errno, state);
	image->img_ptr = img_ptr;
	image->img = img_addr;
	image->width = width;
	image->height = height;
	image->mem_width = image->line_size / (image->bits_per_pixel / 8);
}

static inline int	ft_round(double x)
{
	return ((int)(x + 0.5));
}

void	copy_sprite_to_img(t_tile *tile, t_image_data *sprite)
{
	int		x;
	int		y;
	int		down_factor;
	int		right_factor;
	double	scale;

	y = -1;
	right_factor = SPRITE_TILE_SIZE * (tile->index % 6);
	down_factor = sprite->mem_width * SPRITE_TILE_SIZE * (tile->index / 6);
	scale = (double)SPRITE_TILE_SIZE / MAP_TILE_SIZE;
	while (++y < tile->img_data.height)
	{
		x = -1;
		while (++x < tile->img_data.mem_width)
		{
			((int *) tile->img_data.img)[x + (y * tile->img_data.mem_width)]
				= ((int *)sprite->img)[ft_round(x * scale) + (right_factor)
				+ (sprite->width * ft_round(y * scale) + down_factor)];
		}
	}
}
