/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 00:02:11 by psergio-          #+#    #+#             */
/*   Updated: 2021/07/25 00:02:11 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	clear(t_game_info *game_info)
{
	if (game_info == NULL)
		return ;
	free(game_info->map);
	ft_lstclear(&(game_info->map_rows), free);
	close(game_info->map_fd);
	free(game_info);
}

int	main(int argc, char *argv[])
{
	int			args_valid;
	t_game_info	*game_info;

	args_valid = validate_args(argc, argv);
	if (!args_valid)
		quit_with_error(errno, NULL);
	game_info = parse_arg(argv);
	clear(game_info);
}
