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

int	main(int argc, char *argv[])
{
	int	args_valid;

	args_valid = validate_args(argc, argv);
	if (!args_valid)
		handle_error(ERR_INVALID_ARGS);
	ft_putstr_fd("args valid :)\n", 1);
}
