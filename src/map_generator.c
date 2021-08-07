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

#include "so_long.h"

void	get_map_entity(t_game_state *state, int i, char entity)
{
	if (entity == '0')
		state->map[i] = '~';
	else if (entity == '1')
		state->map[i] = '#';
	else
		state->map[i] = entity;
	if (state->map[i] == 'P')
	{
		if (state->player_pos == 0)
			state->player_pos = i;
		else
			quit_with_error(ERR_MULTIPLAYER, state);
	}
	else if (state->map[i] == 'C')
		state->total_collectibles++;
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
		{
			get_map_entity(state, i, *row++);
			i++;
		}
		lst = lst->next;
	}
}
