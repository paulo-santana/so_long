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

int	main(int argc, char *argv[])
{
	int			args_valid;
	t_game_info	*game_info;

	args_valid = validate_args(argc, argv);
	if (!args_valid)
		quit_with_error(errno);
	game_info = parse_arg(argv);
	printf("the program name is '%s'\n", game_info->program_name);
	free(game_info);
}
