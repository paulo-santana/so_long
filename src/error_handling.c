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

void	handle_error(void)
{
	char	*errmsg;

	errmsg = strerror(errno);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(errmsg, 2);
	ft_putchar_fd('\n', 2);
	exit(errno);
}
