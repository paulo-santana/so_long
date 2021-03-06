/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:17:42 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/25 18:48:17 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static inline t_tile	*select_tile(t_game_state *state, int x, int y,
		t_map_textures *textures)
{
	char	*map_mem;
	int		position;

	map_mem = state->map_mem;
	position = y * state->map.width + x;
	if (map_mem[position] == ENTITY_WALL)
		place_wall(state, x, y);
	else
		put_tile(&textures->floor, state, x, y);
	if (map_mem[position] == ENTITY_COLLECTIBLE)
		put_tile(textures->collectible_current, state, x, y);
	else if (!state->game_finished && map_mem[position] == ENTITY_PLAYER)
		put_tile(textures->player_current, state, x, y);
	else if (map_mem[position] == ENTITY_EXIT)
		put_tile(textures->exit_current, state, x, y);
	else if (map_mem[position] == ENTITY_ENEMY)
		put_tile(textures->enemy_current, state, x, y);
	return (&textures->floor);
}

int	draw_map(t_game_state *state)
{
	int	i;
	int	j;

	i = -1;
	while (++i < state->map.width)
	{
		j = -1;
		while (++j < state->map.height)
			select_tile(state, i, j, &state->textures);
	}
	render_map(state);
	return (0);
}
