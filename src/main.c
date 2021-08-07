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

void	clear(t_game_state *state)
{
	if (state == NULL)
		return ;
	free(state->map);
	ft_lstclear(&(state->map_rows), free);
	close(state->map_fd);
	free(state);
}

void	start_game(t_game_state *game)
{
	t_window	*window;

	window = ft_calloc(sizeof(t_window), 1);
	if (window == NULL)
		quit_with_error(errno, game);
	window->mlx_ptr = mlx_init();
	if (window->mlx_ptr == NULL)
		quit_with_error(errno, game);
	window->win = mlx_new_window(window->mlx_ptr, 800, 600,
			game->program_name);
	if (window->win == NULL)
		quit_with_error(errno, game);
	mlx_hook(window->win, KeyPress, KeyPressMask, key_handler, game);
	mlx_hook(window->win, DestroyNotify, NoEventMask, destroy_handler, game);
	mlx_loop(window->mlx_ptr);
	mlx_destroy_window(window->mlx_ptr, window->win);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	free(window);
}

int	main(int argc, char *argv[])
{
	int				args_valid;
	t_game_state	*state;

	args_valid = validate_args(argc, argv);
	if (!args_valid)
		quit_with_error(errno, NULL);
	state = parse_arg(argv);
	start_game(state);
	clear(state);
}
