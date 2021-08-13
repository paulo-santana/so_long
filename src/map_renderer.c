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
	right_factor = tile->img_data.mem_width * (tile->index % 6);
	down_factor = sprite->mem_width * 32 * (tile->index / 6);
	while (++y < tile->img_data.height)
	{
		x = -1;
		while (++x < tile->img_data.mem_width)
		{
			color = ((int *)sprite->img)[x + (right_factor)
				+ (sprite->width * y + down_factor)];
			((int *) tile->img_data.img)[x + (y * tile->img_data.mem_width)]
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
	generate_mlx_image(state, &state->map.img_data, state->map.width
		* MAP_TILE_SIZE, state->map.height * MAP_TILE_SIZE);
	tile = &state->textures.wall;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->map.sprites_data);
	tile = &state->textures.collectible;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->map.sprites_data);
	tile = &state->textures.floor;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->map.sprites_data);
	tile = &state->textures.exit;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->map.sprites_data);
}

void	put_tile(t_tile *tile, t_game_state *state, int pos_x, int pos_y)
{
	int	x;
	int	y;
	int	down_factor;
	int	right_factor;
	int	color;

	right_factor = pos_x * state->map.img_data.width / state->map.width;
	down_factor = pos_y * state->map.img_data.mem_width * MAP_TILE_SIZE;
	y = pos_y * tile->img_data.height;
	y = -1;
	while (++y < tile->img_data.height)
	{
		x = -1;
		while (++x < tile->img_data.width)
		{
			color = ((int *) tile->img_data.img)[x + (y
					* tile->img_data.mem_width)];
			((int *) state->map.img_data.img)[x + (right_factor)
				+ (state->map.img_data.width * y + down_factor)] = color;
		}
	}
}

//static void display_map(void);

int	draw_map(t_game_state *state)
{
	static int	already_initialized_map;

	if (!already_initialized_map)
	{
		already_initialized_map = 1;
		init_map(state);
	}
	put_tile(&state->textures.wall, state, 0, 0);
	put_tile(&state->textures.wall, state, 1, 0);
	put_tile(&state->textures.wall, state, 2, 0);
	put_tile(&state->textures.wall, state, 3, 0);
	put_tile(&state->textures.wall, state, 4, 0);
	put_tile(&state->textures.collectible, state, 4, 0);
	put_tile(&state->textures.wall, state, 6, 0);
	mlx_put_image_to_window(state->mlx.mlx_ptr, state->mlx.window,
		state->map.img_data.img_ptr, 0, 0);
	return (0);
}
