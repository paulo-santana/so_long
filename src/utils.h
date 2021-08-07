/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 07:41:14 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/07 07:41:14 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "so_long.h"

void	print_map(t_game_state *gi);
void	dump_info(t_game_state *game);
void	print_coordinates(size_t pos, int width);

#endif
