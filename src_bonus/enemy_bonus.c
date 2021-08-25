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

static void	think(t_enemy *enemy)
{
	(void)enemy;
	printf("i'm thinking >:)\n");
}

void	handle_gameover(t_game_state *state)
{
	printf("game over xP\n");
	state->game_finished = 1;
}

void	move_enemies(t_game_state *state)
{
	size_t	i;
	t_enemy	*enemy;
	t_list	*item;

	i = 0;
	item = state->enemy_lst;
	while (i < state->total_enemies)
	{
		item = item->next;
		enemy = item->content;
		think(enemy);
	}
}
