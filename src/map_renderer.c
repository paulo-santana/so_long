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

static void	get_sprites(t_game_state *state)
{
	read_sprite(state, &state->exit.sprites_data, EXIT_SET);
	read_sprite(state, &state->map.sprites_data, TILE_SET);
	read_sprite(state, &state->player.sprites_data, PLAYER_SET);
}

void	init_map(t_game_state *state)
{
	t_tile			*tile;

	state->textures.collectible.index = 29;
	state->textures.floor.index = 7;
	state->textures.player.index = 1;
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
	tile = &state->textures.player;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->player.sprites_data);
	tile = &state->textures.exit;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->exit.sprites_data);
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

t_tile	*select_tile(t_game_state *state, int x, int y, t_map_textures *textures)
{
	char	*map_mem;
	int		position;

	map_mem = state->map_mem;
	position = y * state->map.width + x;
	if (map_mem[position] == ENTITY_WALL)
		place_wall(state, x, y);
	else
		put_tile(&textures->floor, state, x, y);
	if (map_mem[position] == ENTITY_COLLECTIBLE)
		put_tile(&textures->collectible, state, x, y);
	else if (map_mem[position] == ENTITY_PLAYER)
		put_tile(&textures->player, state, x, y);
	else if (map_mem[position] == ENTITY_EXIT)
		put_tile(&textures->exit, state, x, y);
	return (&textures->floor);
}

int	draw_map(t_game_state *state)
{
	static int	already_initialized_map;
	int			i;
	int			j;

	if (!already_initialized_map)
	{
		already_initialized_map = 1;
		init_map(state);
	}
	i = -1;
	while (++i < state->map.width)
	{
		j = -1;
		while (++j < state->map.height)
			select_tile(state, i, j, &state->textures);
	}
	mlx_put_image_to_window(state->mlx.mlx_ptr, state->mlx.window,
		state->map.img_data.img_ptr, 0, 0);
	return (0);
}
