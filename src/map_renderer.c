/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_renderer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:34:52 by psergio-          #+#    #+#             */
/*   Updated: 2021/08/09 11:54:26 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_map_sprites(t_game_state *state)
{
	int				width;
	int				height;
	t_image_data	*img_data;

	img_data = &state->map.map_sprites_data;
	state->map.sprites_img_ptr = mlx_xpm_file_to_image(
			state->mlx.mlx_ptr, TILE_SET, &width, &height);
	state->map.sprites_img = mlx_get_data_addr(state->map.sprites_img_ptr,
			&img_data->bits_per_pixel, &img_data->line_size, &img_data->endian);
}

static void	*get_sprite_for_entity(char entity, t_game_state *state)
{
	int	index;

	if (entity == SL_WALL)
		index = state->textures.north_wall.index;
	return (NULL);
}

void	init_map(t_game_state *state)
{
	t_image_data	*map_data;

	state->textures.collectible.index = 29;
	state->textures.exit.index = 23;
	state->textures.floor.index = 7;
	state->textures.north_wall.index = 1;
	get_map_sprites(state);
	map_data = &state->map.map_img_data;
	state->map.img_ptr = mlx_new_image(state->mlx.mlx_ptr, 800, 600);
	state->map.img = mlx_get_data_addr(state->map.img_ptr,
			&map_data->bits_per_pixel, &map_data->line_size, &map_data->endian);
	get_sprite_for_entity('#', state);
}

int	draw_map(t_game_state *state)
{
	static int	already_initialized_map;

	if (!already_initialized_map)
	{
		already_initialized_map = 1;
		init_map(state);
	}
	mlx_put_image_to_window(state->mlx.mlx_ptr, state->mlx.window,
		state->map.sprites_img_ptr, 0, 0);
	return (0);
}
