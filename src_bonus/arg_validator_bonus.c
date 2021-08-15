/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:57:56 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/05 01:57:56 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	validate_args(int argc, char *argv[])
{
	if (argc != 2 || !ft_ends_with(argv[1], ".ber"))
	{
		errno = EINVAL;
		return (0);
	}
	return (1);
}
