/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 16:49:08 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/08 16:49:08 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "utils.h"

void	clear(t_game_state *state)
{
	if (state == NULL)
		return ;
	free(state->map_mem);
	ft_lstclear(&(state->map_rows), free);
	close(state->map_fd);
	free(state);
}

void	start_game(t_game_state *state)
{
	t_window	*mlx;

	mlx = &state->mlx;
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		quit_with_error(errno, state);
	mlx->window = mlx_new_window(mlx->mlx_ptr, 800, 600,
			state->program_name);
	if (mlx->window == NULL)
		quit_with_error(errno, state);
	mlx_hook(mlx->window, KeyPress, KeyPressMask, key_handler, state);
	mlx_hook(mlx->window, DestroyNotify, NoEventMask, destroy_handler, state);
	mlx_expose_hook(mlx->window, handle_expose, state);
	mlx_loop(mlx->mlx_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->window);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
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
