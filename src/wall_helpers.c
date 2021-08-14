/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:01:08 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/14 14:01:08 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fetch_sprite_tile(t_game_state *state, t_tile *tile)
{
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->map.sprites_data);
}

void	set_walls_index(t_game_state *state)
{
	state->textures.wall_default.index = 1;
	state->textures.wall_left.index = 8;
	state->textures.wall_right.index = 6;
	state->textures.wall_bottom.index = 13;
	state->textures.wall_tl_corner.index = 9;
	state->textures.wall_tr_corner.index = 11;
	state->textures.wall_bl_corner.index = 15;
	state->textures.wall_br_corner.index = 17;
}

void	init_walls(t_game_state *state)
{
	set_walls_index(state);
	fetch_sprite_tile(state, &state->textures.wall_default);
	fetch_sprite_tile(state, &state->textures.wall_left);
	fetch_sprite_tile(state, &state->textures.wall_right);
	fetch_sprite_tile(state, &state->textures.wall_tl_corner);
	fetch_sprite_tile(state, &state->textures.wall_tr_corner);
	fetch_sprite_tile(state, &state->textures.wall_bl_corner);
	fetch_sprite_tile(state, &state->textures.wall_br_corner);
	fetch_sprite_tile(state, &state->textures.wall_bottom);
}

void	place_wall(t_game_state *state, int x, int y)
{
	char	*map_mem;

	map_mem = state->map_mem;
	if (x == 0 && y == state->map.height - 1)
		put_tile(&state->textures.wall_bl_corner, state, x, y);
	else if (x == 0 && y == 0)
		put_tile(&state->textures.wall_tl_corner, state, x, y);
	else if (x == 0)
		put_tile(&state->textures.wall_left, state, x, y);
	else if (x == state->map.width - 1 && y == 0)
		put_tile(&state->textures.wall_tr_corner, state, x, y);
	else if (x == state->map.width - 1 && y == state->map.height - 1)
		put_tile(&state->textures.wall_br_corner, state, x, y);
	else if (x == state->map.width - 1)
		put_tile(&state->textures.wall_right, state, x, y);
	else if (y == state->map.height - 1)
		put_tile(&state->textures.wall_bottom, state, x, y);
	else
		put_tile(&state->textures.wall_default, state, x, y);
}
