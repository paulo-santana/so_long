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

void	init_collectibles(t_game_state *state)
{
	t_tile	*tile;

	state->textures.collectible0.index = 29;
	state->textures.collectible1.index = 34;
	state->textures.collectible2.index = 35;
	tile = &state->textures.collectible0;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->map.sprites_data);
	tile = &state->textures.collectible1;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->map.sprites_data);
	tile = &state->textures.collectible2;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->map.sprites_data);
	state->textures.collectible_current = &state->textures.collectible0;
}

void	init_exit(t_game_state *state)
{
	t_tile	*tile;

	state->textures.exit0.index = 0;
	state->textures.exit1.index = 1;
	state->textures.exit2.index = 2;
	state->textures.exit3.index = 3;
	tile = &state->textures.exit0;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->exit.sprites_data);
	tile = &state->textures.exit1;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->exit.sprites_data);
	tile = &state->textures.exit2;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->exit.sprites_data);
	tile = &state->textures.exit3;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->exit.sprites_data);
	state->textures.exit_current = &state->textures.exit0;
}

void	init_enemies(t_game_state *state)
{
	t_tile	*tile;

	state->textures.enemy0.index = 0;
	state->textures.enemy1.index = 1;
	state->textures.enemy2.index = 2;
	state->textures.enemy3.index = 3;
	tile = &state->textures.enemy0;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->enemies.sprites_data);
	tile = &state->textures.enemy1;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->enemies.sprites_data);
	tile = &state->textures.enemy2;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->enemies.sprites_data);
	tile = &state->textures.enemy3;
	generate_mlx_image(state, &tile->img_data, MAP_TILE_SIZE, MAP_TILE_SIZE);
	copy_sprite_to_img(tile, &state->enemies.sprites_data);
	state->textures.enemy_current = &state->textures.enemy0;
}
