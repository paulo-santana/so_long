/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 07:41:31 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/07 07:41:31 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_coordinates(size_t pos, int width)
{
	printf("%lux%lu",
		pos / width,
		pos % width);
}

void	dump_info(t_game_state *game)
{
	printf("program name: %s\n", game->program_name);
	printf("map name: %s\n", game->map_filename);
	printf("map dimensions: %dx%d\n", game->map_width, game->map_height);
	printf("player position: ");
	print_coordinates(game->player_pos, game->map_width);
	printf("\n");
	printf("moves: %lu\n", game->movement_count);
	printf("collectibles: %lu/%lu\n", game->collected_collectibles,
		game->total_collectibles);
}

void	print_map(t_game_state *gi)
{
	int	i;
	int	map_size;

	i = 0;
	map_size = gi->map_height * gi->map_width;
	while (i < gi->map_height)
	{
		write(1, &gi->map[i * gi->map_width], gi->map_width);
		i++;
		ft_putchar_fd('\n', 1);
	}
}
