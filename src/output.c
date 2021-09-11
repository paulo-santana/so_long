/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:17:14 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/15 18:17:14 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_movements(t_game_state *state)
{
	ft_putstr_fd("\rMovements: ", 1);
	ft_putnbr_fd(state->movement_count, 1);
}
