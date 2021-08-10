/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_renderer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:34:52 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/09 11:54:26 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <errno.h>

static void	get_mlx_image(t_game_state *state,
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
}

static void	get_map_sprites(t_game_state *state)
{
	int				width;
	int				height;
	t_image_data	*sprites;

	sprites = &state->map.sprites_data;
	sprites->img_ptr = mlx_xpm_file_to_image(
			state->mlx.mlx_ptr, TILE_SET, &width, &height);
	sprites->img = mlx_get_data_addr(sprites->img_ptr, &sprites->bits_per_pixel,
			&sprites->line_size, &sprites->endian);
	sprites->width = width;
	sprites->height = height;
}

static void	copy_sprite_to_img(t_tile *tile, t_image_data *sprite)
{
	int	x;
	int	y;

	y = -1;
	while (++y < tile->img_data.height)
	{
		x = -1;
		while (++x < tile->img_data.width)
		{
			((int *)tile->img_data.img)[x + (y * tile->img_data.width)]
				= ((int *)sprite->img)[
				x + tile->img_data.width * (tile->index) + sprite->width * y
			];
		}
	}
}

void	init_map(t_game_state *state)
{
	t_image_data	*map_data;

	state->textures.collectible.index = 8;
	state->textures.exit.index = 23;
	state->textures.floor.index = 7;
	state->textures.wall.index = 1;
	get_map_sprites(state);
	map_data = &state->map.img_data;
	get_mlx_image(state, &state->textures.collectible.img_data, 32, 32);
	copy_sprite_to_img(&state->textures.collectible, &state->map.sprites_data);
	mlx_put_image_to_window(state->mlx.mlx_ptr, state->mlx.window,
		state->textures.collectible.img_data.img_ptr, 100, 120);
}

int	draw_map(t_game_state *state)
{
	static int	already_initialized_map;

	if (!already_initialized_map)
	{
		already_initialized_map = 1;
		init_map(state);
	}
	return (0);
}
