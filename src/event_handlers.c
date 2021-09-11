/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:11:25 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/07 10:11:25 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish(t_game_state *state)
{
	clear(state);
	exit(0);
}

int	key_handler(int keycode, void *param)
{
	t_game_state	*state;

	state = param;
	if (keycode == XK_Escape || keycode == 'q')
		finish(state);
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

int	destroy_handler(void *param)
{
	t_game_state	*state;

	state = param;
	finish(state);
	return (0);
}

int	handle_expose(void *param)
{
	t_game_state	*state;

	state = param;
	draw_map(state);
	return (0);
}
