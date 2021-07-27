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

#include "so_long.h"

t_game_info	*parse_arg(char *args[])
{
	t_game_info	*game_info;

	game_info = malloc(sizeof(t_game_info));
	if (game_info == NULL)
		return (NULL);
	game_info->program_name = args[0];
	game_info->map_filename = args[1];
	get_map(game_info);
	return (game_info);
}
