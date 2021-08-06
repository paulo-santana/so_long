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

void	generate_map(t_game_info *game_info)
{
	t_list	*lst;
	char	*row;
	int		i;

	i = 0;
	lst = game_info->map_rows;
	while (lst)
	{
		row = lst->content;
		while (*row)
			game_info->map[i++] = *row++;
		lst = lst->next;
	}
}
