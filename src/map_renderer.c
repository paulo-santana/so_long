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

static void	get_map_sprites(t_game_state *state)
{
	read_sprite(state, &state->map.sprites_data, TILE_SET);
}

static void	copy_sprite_to_img(t_tile *tile, t_image_data *sprite)
{
	int				x;
	int				y;
	int				down_factor;
	int				right_factor;
	unsigned int	color;

	y = -1;
	right_factor = tile->img_data.width * (tile->index % 6);
	down_factor = sprite->width * 32 * (tile->index / 6);
	while (++y < tile->img_data.height)
	{
		x = -1;
		while (++x < tile->img_data.width)
		{
			color = ((unsigned int *)sprite->img)[x + (right_factor)
				+ (sprite->width * y + down_factor)];
			((unsigned int *)tile->img_data.img)[x + (y * tile->img_data.width)]
				= color;
		}
	}
}

void	init_map(t_game_state *state)
{
	t_tile			*tile;

	state->textures.collectible.index = 29;
	state->textures.exit.index = 23;
	state->textures.floor.index = 7;
	state->textures.wall.index = 1;
	get_map_sprites(state);
	tile = &state->textures.wall;
	generate_mlx_image(state, &tile->img_data, 32, 32);
	copy_sprite_to_img(tile, &state->map.sprites_data);
	tile = &state->textures.collectible;
	generate_mlx_image(state, &tile->img_data, 32, 32);
	copy_sprite_to_img(tile, &state->map.sprites_data);
	tile = &state->textures.floor;
	generate_mlx_image(state, &tile->img_data, 32, 32);
	copy_sprite_to_img(tile, &state->map.sprites_data);
	tile = &state->textures.exit;
	generate_mlx_image(state, &tile->img_data, 32, 32);
	copy_sprite_to_img(tile, &state->map.sprites_data);
}

void	draw_tile(t_tile *tile, t_game_state *state, int x, int y)
{
	int	x_position;
	int	y_position;

	x_position = x * tile->img_data.width;
	y_position = y * tile->img_data.height;
	mlx_put_image_to_window(state->mlx.mlx_ptr, state->mlx.window,
		tile->img_data.img_ptr, x_position, y_position);
}

int	draw_map(t_game_state *state)
{
	static int	already_initialized_map;
	int			i;

	if (!already_initialized_map)
	{
		already_initialized_map = 1;
		init_map(state);
	}
	i = 0;
	while (i < 20)
		draw_tile(&state->textures.wall, state, i++, 0);
	i = 0;
	draw_tile(&state->textures.floor, state, 1, i++);
	draw_tile(&state->textures.collectible, state, 4, i++);
	draw_tile(&state->textures.exit, state, 2, i++);
	draw_tile(&state->textures.exit, state, 3, i++);
	return (0);
}
