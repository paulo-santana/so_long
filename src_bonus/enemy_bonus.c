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

static void	animate_enemies(t_game_state *state, int frame)
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
	int		*i;
	size_t	result;

	i = malloc(1);
	result = (size_t) i % 4;
	if (result == 0)
		return (position - state->map.width);
	else if (result == 1)
		return (position + state->map.width);
	else if (result == 2)
		return (position - 1);
	else
		return (position + 1);
	free(i);
}

static void	think(t_game_state *state, size_t position)
{
	size_t	intended_position;

	intended_position = get_intended_position(state, position);
	printf("[enemy %d] i'm thinking of goint to %d>:)\n",
		(int)position, (int)intended_position);
}

void	handle_gameover(t_game_state *state)
{
	printf("game over xP\n");
	state->game_finished = 1;
}

void	move_enemies(t_game_state *state)
{
	static int	frame;
	size_t		i;
	size_t		*enemy_positions;

	frame++;
	animate_enemies(state, frame);
	if (frame > 3)
		frame = 0;
	i = 0;
	enemy_positions = state->enemy_positions;
	if (state->game_finished)
		return ;
	while (i < state->total_enemies)
	{
		think(state, enemy_positions[i]);
		i++;
	}
}
