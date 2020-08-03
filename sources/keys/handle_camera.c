/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:36:06 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/03 17:55:42 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	handle_cam_right(t_display_config *display_config)
{
	double old_dir_x;
	double old_fov_x;

	check_active_key(display_config);
	old_dir_x = D_CONFIG->init_dir.x;
	old_fov_x = D_CAM->fov.x;
	D_CONFIG->init_dir.x = D_CONFIG->init_dir.x * cos(-ROT_SPEED) -
		D_CONFIG->init_dir.y * sin(-ROT_SPEED);
	D_CONFIG->init_dir.y = old_dir_x * sin(-ROT_SPEED) + D_CONFIG->init_dir.y *
		cos(-ROT_SPEED);
	D_CAM->fov.x = D_CAM->fov.x * cos(-ROT_SPEED) - D_CAM->fov.y *
		sin(-ROT_SPEED);
	D_CAM->fov.y = old_fov_x * sin(-ROT_SPEED) + D_CAM->fov.y * cos(-ROT_SPEED);
	mlx_destroy_image(D_DATA->mlx_ptr, D_DATA->mlx_img);
	D_DATA->mlx_img = mlx_new_image(D_DATA->mlx_ptr, D_CONFIG->resolution.x,
		D_CONFIG->resolution.y);
	reload_scene(display_config, 0);
}

void	handle_cam_left(t_display_config *display_config)
{
	double old_dir_x;
	double old_fov_x;

	check_active_key(display_config);
	old_dir_x = D_CONFIG->init_dir.x;
	old_fov_x = D_CAM->fov.x;
	D_CONFIG->init_dir.x = D_CONFIG->init_dir.x * cos(ROT_SPEED) -
		D_CONFIG->init_dir.y * sin(ROT_SPEED);
	D_CONFIG->init_dir.y = old_dir_x * sin(ROT_SPEED) + D_CONFIG->init_dir.y *
		cos(ROT_SPEED);
	D_CAM->fov.x = D_CAM->fov.x * cos(ROT_SPEED) - D_CAM->fov.y *
		sin(ROT_SPEED);
	D_CAM->fov.y = old_fov_x * sin(ROT_SPEED) + D_CAM->fov.y * cos(ROT_SPEED);
	mlx_destroy_image(D_DATA->mlx_ptr, D_DATA->mlx_img);
	D_DATA->mlx_img = mlx_new_image(D_DATA->mlx_ptr, D_CONFIG->resolution.x,
		D_CONFIG->resolution.y);
	reload_scene(display_config, 0);
}
