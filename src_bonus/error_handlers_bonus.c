/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 01:57:06 by psergio-          #+#    #+#             */
/*   Updated: 2021/07/25 01:57:06 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*get_error_message(int err)
{
	char	*messages[ERR_SIZE];

	messages[ERR_INVALID_MAP] = "Invalid map.";
	messages[ERR_MULTIPLAYER] = "Multiplayer is not implemented yet.";
	messages[ERR_NO_PLAYER] = "Where is the player?";
	messages[ERR_NO_EXIT] = "Map without exit.";
	messages[ERR_NO_COLLECT] = "Map without collectibles.";
	return (messages[err]);
}

static void	print_error(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
}

void	quit_with_error(int my_errno, t_game_state *state)
{
	char	*errmsg;
	int		exit_code;

	if (errno == 0)
	{
		errmsg = get_error_message(my_errno);
		exit_code = my_errno + 1;
	}
	else
	{
		exit_code = errno;
		errmsg = strerror(errno);
	}
	print_error(errmsg);
	clear(state);
	exit(exit_code);
}
