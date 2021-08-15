/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:48:20 by psergio-          #+#    #+#             */
/*   Updated: 2021/07/27 00:48:20 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_game_state	*parse_arg(char *args[])
{
	t_game_state	*state;

	state = ft_calloc(sizeof(t_game_state), 1);
	if (state == NULL)
		quit_with_error(errno, state);
	state->program_name = args[0];
	state->map_filename = args[1];
	get_map(state);
	return (state);
}
