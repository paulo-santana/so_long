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

int	key_handler(int keycode, void *param)
{
	(void) param;
	printf("%d - %c\n", keycode, keycode);
	return (0);
}

void	start_game(t_game_info *game_info)
{
	t_window	*window;

	window = ft_calloc(sizeof(t_window), 1);
	if (window == NULL)
		quit_with_error(errno, game_info);
	window->mlx_ptr = mlx_init();
	if (window->mlx_ptr == NULL)
		quit_with_error(errno, game_info);
	window->win = mlx_new_window(window->mlx_ptr, 800, 600,
			game_info->program_name);
	if (window->win == NULL)
		quit_with_error(errno, game_info);
	mlx_key_hook(window->win, key_handler, game_info);
	mlx_loop(window->mlx_ptr);
	mlx_destroy_window(window->mlx_ptr, window->win);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	free(window);
}

int	main(int argc, char *argv[])
{
	int			args_valid;
	t_game_info	*game_info;

	args_valid = validate_args(argc, argv);
	if (!args_valid)
		quit_with_error(errno, NULL);
	game_info = parse_arg(argv);
	start_game(game_info);
	clear(game_info);
}
