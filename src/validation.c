/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:00:29 by psergio-          #+#    #+#             */
/*   Updated: 2021/07/25 02:00:29 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_args(int argc, char *argv[])
{
	if (argc != 2 || !ft_ends_with(argv[1], ".ber"))
	{
		errno = EINVAL;
		return (0);
	}
	return (1);
}
