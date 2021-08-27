/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animated_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 15:06:34 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/15 15:06:34 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_player_animated_sprites(t_game_state *state)
{
	t_tile	*content;
	t_list	*first;

	content = &state->textures.player0;
	first = ft_lstnew(content);
	ft_lstadd_back(&state->player.img_data.images, first);
	content = &state->textures.player1;
	ft_lstadd_back(&state->player.img_data.images, ft_lstnew(content));
	content = &state->textures.player2;
	ft_lstadd_back(&state->player.img_data.images, ft_lstnew(content));
	content = &state->textures.player3;
	ft_lstadd_back(&state->player.img_data.images, ft_lstnew(content));
	ft_lstlast(first)->next = first;
}

void	animate_collectible(t_game_state *state, int frame)
{
	if (frame == 0)
		state->textures.collectible_current = &state->textures.collectible0;
	else if (frame == 1)
		state->textures.collectible_current = &state->textures.collectible1;
	else if (frame == 2)
		state->textures.collectible_current = &state->textures.collectible2;
	else if (frame == 3)
		state->textures.collectible_current = &state->textures.collectible1;
}

void	animate_player(t_game_state *state, int frame)
{
	if (frame == 0)
		state->textures.player_current = &state->textures.player0;
	else if (frame == 1)
		state->textures.player_current = &state->textures.player1;
	else if (frame == 2)
		state->textures.player_current = &state->textures.player2;
	else if (frame == 3)
		state->textures.player_current = &state->textures.player3;
}

void	animate_exit(t_game_state *state, int frame)
{
	if (frame == 0)
		state->textures.exit_current = &state->textures.exit0;
	else if (frame == 1)
		state->textures.exit_current = &state->textures.exit1;
	else if (frame == 2)
		state->textures.exit_current = &state->textures.exit2;
	else if (frame == 3)
		state->textures.exit_current = &state->textures.exit3;
}

void	prepare_next_frame(t_game_state *state)
{
	static int	frame;
	static int	enemy_tick;

	animate_player(state, frame);
	animate_collectible(state, frame);
	animate_exit(state, frame);
	animate_enemies(state, frame);
	if (frame++ > 3)
		frame = 0;
	if (enemy_tick++ > 5)
	{
		move_enemies(state);
		enemy_tick = 0;
	}
}
