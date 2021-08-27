/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:21:06 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/05 14:21:06 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_map_entity(t_game_state *state, int i, char entity)
{
	if (entity == '0')
		state->map_mem[i] = ENTITY_FLOOR;
	else if (entity == '1')
		state->map_mem[i] = ENTITY_WALL;
	else
		state->map_mem[i] = entity;
	if (state->map_mem[i] == ENTITY_PLAYER)
	{
		if (state->player_pos == 0)
			state->player_pos = i;
		else
			quit_with_error(ERR_MULTIPLAYER, state);
	}
	else if (state->map_mem[i] == ENTITY_COLLECTIBLE)
		state->total_collectibles++;
	else if (state->map_mem[i] == ENTITY_EXIT)
		state->exits++;
	else if (state->map_mem[i] == ENTITY_ENEMY)
		state->total_enemies++;
}

void	fetch_enemies(t_game_state *state)
{
	char	*map_mem;
	size_t	map_len;
	size_t	map_index;
	size_t	enemy_index;

	enemy_index = 0;
	map_index = 0;
	map_mem = state->map_mem;
	state->enemy_positions = malloc(sizeof(size_t) * state->total_enemies);
	map_len = state->map.width * state->map.height;
	while (map_index < map_len)
	{
		if (map_mem[map_index] == ENTITY_ENEMY)
			state->enemy_positions[enemy_index++] = map_index;
		map_index++;
	}
}

void	generate_map(t_game_state *state)
{
	t_list	*lst;
	char	*row;
	int		i;

	i = 0;
	state->player_pos = 0;
	lst = state->map_rows;
	while (lst)
	{
		row = lst->content;
		while (*row)
			get_map_entity(state, i++, *row++);
		lst = lst->next;
	}
	if (state->player_pos == 0)
		quit_with_error(ERR_NO_PLAYER, state);
	if (state->exits == 0)
		quit_with_error(ERR_NO_EXIT, state);
	if (state->total_collectibles == 0)
		quit_with_error(ERR_NO_COLLECT, state);
	fetch_enemies(state);
}
