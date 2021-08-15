/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:13:18 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/07 10:13:18 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	get_intended_position(t_directions direction, t_game_state *state)
{
	size_t	intended_position;
	size_t	player_position;

	player_position = state->player_pos;
	intended_position = player_position;
	if (direction == DIRECTION_UP)
		intended_position = player_position - state->map.width;
	else if (direction == DIRECTION_DOWN)
		intended_position = player_position + state->map.width;
	else if (direction == DIRECTION_LEFT)
		intended_position = player_position - 1;
	else if (direction == DIRECTION_RIGHT)
		intended_position = player_position + 1;
	return (intended_position);
}

void	handle_exit(t_game_state *state)
{
	if (state->collected_collectibles < state->total_collectibles)
		return ;
	printf("Congratula...tulations!\n");
	finish();
}

void	move_to(size_t intended_position, t_game_state *state)
{
	if (intended_position == state->player_pos)
		return ;
	if (state->map_mem[intended_position] == ENTITY_WALL)
		return ;
	if (state->map_mem[intended_position] == ENTITY_EXIT)
		return (handle_exit(state));
	if (state->map_mem[intended_position] == ENTITY_COLLECTIBLE)
		state->collected_collectibles++;
	state->map_mem[intended_position] = ENTITY_PLAYER;
	state->map_mem[state->player_pos] = ENTITY_FLOOR;
	state->player_pos = intended_position;
	state->movement_count++;
}

void	move(t_directions direction, t_game_state *state)
{
	size_t	intended_position;

	intended_position = get_intended_position(direction, state);
	move_to(intended_position, state);
	draw_map(state);
}
