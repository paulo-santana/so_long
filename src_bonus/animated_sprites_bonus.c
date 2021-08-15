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

void	prepare_next_frame(t_game_state *state)
{
	static int	counter;

	if (counter == 0)
		state->textures.player_current = &state->textures.player0;
	else if (counter == 1)
		state->textures.player_current = &state->textures.player1;
	else if (counter == 2)
		state->textures.player_current = &state->textures.player2;
	else if (counter == 3)
		state->textures.player_current = &state->textures.player3;
	counter ++;
	if (counter > 3)
		counter = 0;
}
