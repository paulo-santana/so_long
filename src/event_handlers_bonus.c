/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:11:25 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/15 01:06:32 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish(void)
{
	exit(0);
}

int	key_handler(int keycode, void *param)
{
	t_game_state	*state;

	state = param;
	if (keycode == XK_Escape || keycode == 'q')
		finish();
	if (keycode == 'w')
		move(DIRECTION_UP, state);
	else if (keycode == 'a')
		move(DIRECTION_LEFT, state);
	else if (keycode == 's')
		move(DIRECTION_DOWN, state);
	else if (keycode == 'd')
		move(DIRECTION_RIGHT, state);
	draw_map(state);
	return (0);
}

int	destroy_handler(void)
{
	finish();
	return (0);
}

int	loop_handler(t_game_state *state)
{
	static int	tick;

	tick++;
	if (tick < 1000)
		return (0);
	printf("tick is 1000!\n");
	tick = 0;
	(void)state;
	return (0);
}

int	handle_expose(t_game_state *state)
{
	draw_map(state);
	return (0);
}