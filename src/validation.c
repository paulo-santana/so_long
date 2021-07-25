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
	char	*file_name;

	if (argc != 2)
		return (0);
	file_name = argv[1];
	if (!ft_ends_with(file_name, ".ber"))
		return (0);
	return (1);
}
