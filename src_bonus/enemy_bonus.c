/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:07:12 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/25 19:07:12 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animate_enemies(t_game_state *state, int frame)
{
	if (frame == 0)
		state->textures.enemy_current = &state->textures.enemy0;
	else if (frame == 1)
		state->textures.enemy_current = &state->textures.enemy1;
	else if (frame == 2)
		state->textures.enemy_current = &state->textures.enemy2;
	else if (frame == 3)
		state->textures.enemy_current = &state->textures.enemy3;
}

static size_t	get_intended_position(t_game_state *state, size_t position)
{
	int		i;
	size_t	result;

	if (state->player_pos == position - state->map.width)
		return (position - state->map.width);
	else if (state->player_pos == position + state->map.width)
		return (position + state->map.width);
	else if (state->player_pos == position - 1)
		return (position - 1);
	else if (state->player_pos == position + 1)
		return (position + 1);
	i = get_random_int(state->random_seed);
	result = (size_t) i % 4;
	if (result == 0)
		return (position - state->map.width);
	else if (result == 1)
		return (position + state->map.width);
	else if (result == 2)
		return (position - 1);
	else
		return (position + 1);
}

static size_t	think(t_game_state *state, size_t position)
{
	size_t		intended_position;

	intended_position = get_intended_position(state, position);
	printf("[enemy %d] i'm thinking of going to %d >:)\n",
		(int)position, (int)intended_position);
	if (state->map_mem[intended_position] == ENTITY_WALL
		|| state->map_mem[intended_position] == ENTITY_COLLECTIBLE
		|| state->map_mem[intended_position] == ENTITY_EXIT
		|| state->map_mem[intended_position] == ENTITY_ENEMY
	)
		return (position);
	return (intended_position);
}

void	handle_gameover(t_game_state *state)
{
	printf("game over xP\n");
	state->game_finished = 1;
}

void	move_enemies(t_game_state *state)
{
	size_t		i;
	size_t		*enemy_positions;
	size_t		new_position;

	if (state->game_finished)
		return ;
	i = -1;
	enemy_positions = state->enemy_positions;
	while (++i < state->total_enemies)
	{
		new_position = think(state, enemy_positions[i]);
		if (new_position == enemy_positions[i])
			continue ;
		state->map_mem[new_position] = ENTITY_ENEMY;
		state->map_mem[enemy_positions[i]] = ENTITY_FLOOR;
		enemy_positions[i] = new_position;
		if (new_position == state->player_pos)
			handle_gameover(state);
	}
}
