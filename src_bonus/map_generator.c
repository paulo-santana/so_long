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
		state->map_mem[i] = '~';
	else if (entity == '1')
		state->map_mem[i] = '#';
	else
		state->map_mem[i] = entity;
	if (state->map_mem[i] == 'P')
	{
		if (state->player_pos == 0)
			state->player_pos = i;
		else
			quit_with_error(ERR_MULTIPLAYER, state);
	}
	else if (state->map_mem[i] == 'C')
		state->total_collectibles++;
	else if (state->map_mem[i] == 'E')
		state->exits++;
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
}
