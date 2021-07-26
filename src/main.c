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

t_game_info	*parse_arg(char *args[])
{
	t_game_info	*gi;

	gi = malloc(sizeof(t_game_info));
	if (gi == NULL)
		return (NULL);
	gi->program_name = args[0];
	return (gi);
}

int	main(int argc, char *argv[])
{
	int			args_valid;
	t_game_info	*game_info;

	args_valid = validate_args(argc, argv);
	if (!args_valid)
		handle_error(ERR_INVALID_ARGS);
	game_info = parse_arg(argv);
	printf("the program name is '%s'\n", game_info->program_name);
	free(game_info);
}
