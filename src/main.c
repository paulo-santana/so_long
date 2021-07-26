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

void	get_map(t_game_info *game_info)
{
	int	fd;

	fd = open(game_info->map_filename, O_RDONLY);
	if (fd < 0)
		handle_error();
}

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

int	main(int argc, char *argv[])
{
	int			args_valid;
	t_game_info	*game_info;

	args_valid = validate_args(argc, argv);
	if (!args_valid)
		handle_error();
	game_info = parse_arg(argv);
	printf("the program name is '%s'\n", game_info->program_name);
	free(game_info);
}
