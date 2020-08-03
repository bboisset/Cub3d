/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:36:12 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/03 17:41:01 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	handle_go_up(t_display_config *display_config)
{
	display_config->key.up_active = 1;
	if (D_CONFIG->map[(int)(D_CAM->pos.x + D_CONFIG->init_dir.x *
		moveSpeed)][(int)D_CAM->pos.y] - 48 == 0)
		D_CAM->pos.x += D_CONFIG->init_dir.x * moveSpeed;
	if (D_CONFIG->map[(int)D_CAM->pos.x][(int)(D_CAM->pos.y +
		D_CONFIG->init_dir.y * moveSpeed)] - 48 == 0)
		D_CAM->pos.y += D_CONFIG->init_dir.y * moveSpeed;
	mlx_destroy_image(D_DATA->mlx_ptr, D_DATA->mlx_img);
	D_DATA->mlx_img = mlx_new_image(D_DATA->mlx_ptr, D_CONFIG->resolution.x,
		D_CONFIG->resolution.y);
	reload_scene(display_config, 1);
}

void	handle_go_down(t_display_config *display_config)
{
	display_config->key.down_active = 1;
	if (D_CONFIG->map[(int)(D_CAM->pos.x - D_CONFIG->init_dir.x *
		moveSpeed)][(int)D_CAM->pos.y] - 48 == 0)
		D_CAM->pos.x -= D_CONFIG->init_dir.x * moveSpeed;
	if (D_CONFIG->map[(int)D_CAM->pos.x][(int)(D_CAM->pos.y -
		D_CONFIG->init_dir.y * moveSpeed)] - 48 == 0)
		D_CAM->pos.y -= D_CONFIG->init_dir.y * moveSpeed;
	mlx_destroy_image(D_DATA->mlx_ptr, D_DATA->mlx_img);
	D_DATA->mlx_img = mlx_new_image(D_DATA->mlx_ptr,
		D_CONFIG->resolution.x, D_CONFIG->resolution.y);
	reload_scene(display_config, 1);
}
void	handle_go_left(t_display_config *display_config)
{
	if (D_CONFIG->map[(int)(D_CAM->pos.x - D_CAM->fov.x *
		moveSpeedSec)][(int)D_CAM->pos.y] - 48 == 0)
		D_CAM->pos.x -= D_CAM->fov.x * moveSpeed;
	if (D_CONFIG->map[(int)D_CAM->pos.x][(int)(D_CAM->pos.y - D_CAM->fov.y *
		moveSpeedSec)] - 48 == 0)
		D_CAM->pos.y -= D_CAM->fov.y * moveSpeed;
	mlx_destroy_image(D_DATA->mlx_ptr, D_DATA->mlx_img);
	D_DATA->mlx_img = mlx_new_image(D_DATA->mlx_ptr, D_CONFIG->resolution.x,
		D_CONFIG->resolution.y);
	reload_scene(display_config, 1);
}
void	handle_go_right(t_display_config *display_config)
{
	if (D_CONFIG->map[(int)(D_CAM->pos.x + D_CAM->fov.x *
		moveSpeedSec)][(int)D_CAM->pos.y] - 48 == 0)
		D_CAM->pos.x += D_CAM->fov.x * moveSpeed;
	if (D_CONFIG->map[(int)D_CAM->pos.x][(int)(D_CAM->pos.y + D_CAM->fov.y *
		moveSpeedSec)] - 48 == 0)
		D_CAM->pos.y += D_CAM->fov.y * moveSpeed;
	mlx_destroy_image(D_DATA->mlx_ptr, D_DATA->mlx_img);
	D_DATA->mlx_img = mlx_new_image(D_DATA->mlx_ptr, D_CONFIG->resolution.x,
		D_CONFIG->resolution.y);
	reload_scene(display_config, 1);
}
