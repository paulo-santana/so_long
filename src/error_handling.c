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

void	handle_error(int err)
{
	ft_putstr_fd("Error\n", 2);
	if (err == ERR_INVALID_ARGS)
		ft_putstr_fd("Invalid argument.", 2);
	ft_putchar_fd('\n', 2);
	exit(err);
}
