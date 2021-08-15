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

#include "so_long_bonus.h"

static void	get_sprites(t_game_state *state)
{
	read_sprite(state, &state->exit.sprites_data, EXIT_SET);
	read_sprite(state, &state->map.sprites_data, TILE_SET);
	read_sprite(state, &state->player.sprites_data, PLAYER_SET);
}

void	init_map(t_game_state *state)
{
	t_tile	*tile;

	state->textures.collectible.index = 29;
	state->textures.floor.index = 7;
	state->textures.exit.index = 1;
	get_sprites(state);
	generate_mlx_image(state, &state->map.img_data, state->map.width
		* MAP_TILE_SIZE, state->map.height * MAP_TILE_SIZE);
	tile = &state->textures.collectible;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->map.sprites_data);
	tile = &state->textures.floor;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->map.sprites_data);
	tile = &state->textures.exit;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->exit.sprites_data);
	init_player(state);
	init_walls(state);
}

static inline void	put_alpha_pixel(int *dest, int src)
{
	int	alpha;
	int	red;
	int	green;
	int	blue;

	alpha = (src & 0xff000000) >> 24;
	if (alpha == 0xff)
		return ;
	if (alpha == 00)
	{
		*dest = src;
		return ;
	}
	red = (((*dest & 0xff0000) >> 16) * alpha + ((src & 0xff0000 >> 16)
				* (255 - alpha))) >> 8;
	green = (((*dest & 0xff00) >> 8 ) * alpha + ((src & 0xff00 >> 8)
				* (255 - alpha))) >> 8;
	blue = ((*dest & 0xff) * alpha + ((src & 0xff) * (255 - alpha))) >> 8;
	*dest = (alpha << 24 | red << 16 | green << 8 | blue);
}

inline void	put_tile(t_tile *tile, t_game_state *state, int x, int y)
{
	int	down_factor;
	int	right_factor;
	int	map_line;
	int	tile_line;

	right_factor = x * state->map.img_data.width / state->map.width;
	down_factor = y * state->map.img_data.mem_width * MAP_TILE_SIZE;
	y = -1;
	while (++y < tile->img_data.height)
	{
		x = -1;
		map_line = y * state->map.img_data.width + down_factor;
		tile_line = y * tile->img_data.mem_width;
		while (++x < tile->img_data.width)
		{
			put_alpha_pixel(&((int *) state->map.img_data.img)[x + right_factor
				+ map_line], ((int *) tile->img_data.img)[x + (tile_line)]);
		}
	}
}

void	render_map(t_game_state *state)
{
	mlx_put_image_to_window(state->mlx.mlx_ptr, state->mlx.window,
		state->map.img_data.img_ptr, 0, 0);
}
