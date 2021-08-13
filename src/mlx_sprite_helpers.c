/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:14:56 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/12 13:14:56 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_sprite(t_game_state *state, t_image_data *image, char *filename)
{
	void	*img_ptr;
	void	*img_addr;
	int		width;
	int		height;

	img_ptr = mlx_xpm_file_to_image(
			state->mlx.mlx_ptr, filename, &width, &height);
	if (img_ptr == NULL)
		quit_with_error(errno, state);
	img_addr = mlx_get_data_addr(img_ptr, &image->bits_per_pixel,
			&image->line_size, &image->endian);
	if (img_addr == NULL)
		quit_with_error(errno, state);
	image->img_ptr = img_ptr;
	image->img = img_addr;
	image->width = width;
	image->height = height;
	image->mem_width = image->line_size / (image->bits_per_pixel / 8);
}
