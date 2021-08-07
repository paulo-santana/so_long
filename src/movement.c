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

#include "so_long.h"
#include "utils.h"
#include <stddef.h>

size_t	get_intended_position(t_directions direction, t_game_state *state)
{
	size_t	intended_position;
	size_t	player_position;

	player_position = state->player_pos;
	intended_position = player_position;
	if (direction == DIRECTION_UP)
		intended_position = player_position - state->map_width;
	else if (direction == DIRECTION_DOWN)
		intended_position = player_position + state->map_width;
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
	exit(0);
}

void	move_to(size_t intended_position, t_game_state *state)
{
	if (intended_position == state->player_pos)
		return ;
	if (state->map[intended_position] == '#')
		return ;
	if (state->map[intended_position] == 'E')
		return (handle_exit(state));
	if (state->map[intended_position] == 'C')
		state->collected_collectibles++;
	state->map[intended_position] = '*';
	state->map[state->player_pos] = '~';
	state->player_pos = intended_position;
	state->movement_count++;
}

void	move(t_directions direction, t_game_state *state)
{
	size_t	intended_position;

	intended_position = get_intended_position(direction, state);
	move_to(intended_position, state);
}
