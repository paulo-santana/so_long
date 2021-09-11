/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:40:23 by psergio-          #+#    #+#             */
/*   Updated: 2021/09/06 14:40:23 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_animated_sprites(t_game_state *state)
{
	void	*mlx;

	mlx = state->mlx.mlx_ptr;
	mlx_destroy_image(mlx, state->textures.exit0.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.exit1.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.exit2.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.exit3.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.player0.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.player1.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.player2.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.player3.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.collectible0.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.collectible1.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.collectible2.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.enemy0.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.enemy1.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.enemy2.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.enemy3.img_data.img_ptr);
}

void	destroy_sprites(t_game_state *state)
{
	void	*mlx;

	mlx = state->mlx.mlx_ptr;
	mlx_destroy_image(mlx, state->map.img_data.img_ptr);
	mlx_destroy_image(mlx, state->map.sprites_data.img_ptr);
	mlx_destroy_image(mlx, state->exit.sprites_data.img_ptr);
	mlx_destroy_image(mlx, state->player.sprites_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.floor.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.wall_left.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.wall_right.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.wall_bottom.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.wall_tl_corner.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.wall_tr_corner.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.wall_bl_corner.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.wall_br_corner.img_data.img_ptr);
	mlx_destroy_image(mlx, state->textures.wall_default.img_data.img_ptr);
	mlx_destroy_image(mlx, state->cleaner.img_ptr);
	mlx_destroy_image(mlx, state->enemies.sprites_data.img_ptr);
	destroy_animated_sprites(state);
}

void	clear(t_game_state *state)
{
	if (state == NULL)
		return ;
	free(state->map_mem);
	ft_lstclear(&(state->map_rows), free);
	if (state->mlx.mlx_ptr)
	{
		destroy_sprites(state);
		mlx_destroy_window(state->mlx.mlx_ptr, state->mlx.window);
		mlx_loop_end(state->mlx.mlx_ptr);
		mlx_destroy_display(state->mlx.mlx_ptr);
		free(state->mlx.mlx_ptr);
	}
	free(state->enemy_positions);
	free(state);
	exit(0);
}
