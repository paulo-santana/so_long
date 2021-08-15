/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprite_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 15:38:16 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/15 15:38:16 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_player(t_game_state *state)
{
	t_tile	*tile;

	state->textures.player0.index = 0;
	state->textures.player1.index = 1;
	state->textures.player2.index = 2;
	state->textures.player3.index = 3;
	tile = &state->textures.player0;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->player.sprites_data);
	tile = &state->textures.player1;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->player.sprites_data);
	tile = &state->textures.player2;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->player.sprites_data);
	tile = &state->textures.player3;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->player.sprites_data);
	state->textures.player_current = &state->textures.player0;
}
