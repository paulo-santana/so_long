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

#include "so_long.h"

char	*get_error_message(int err)
{
	char	*messages[sizeof(enum e_errors)];

	messages[ERR_INVALID_MAP] = "Invalid map.";
	return (messages[err]);
}

void	quit_with_error(int my_errno)
{
	char	*errmsg;

	if (errno == 0)
		errmsg = get_error_message(my_errno);
	else
		errmsg = strerror(errno);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(errmsg, 2);
	ft_putchar_fd('\n', 2);
	exit(errno);
}
