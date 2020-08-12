/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:36:06 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/10 20:14:28 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	handle_cam_right(t_full_conf *full_conf)
{
	double old_dir_x;
	double old_fov_x;

	//check_active_key(full_conf);
	old_dir_x = full_conf->config->init_dir.x;
	old_fov_x = full_conf->camera->fov.x;
	full_conf->config->init_dir.x = full_conf->config->init_dir.x *
		cos(-ROT_SPEED) - full_conf->config->init_dir.y * sin(-ROT_SPEED);
	full_conf->config->init_dir.y = old_dir_x * sin(-ROT_SPEED) +
		full_conf->config->init_dir.y * cos(-ROT_SPEED);
	full_conf->camera->fov.x = full_conf->camera->fov.x * cos(-ROT_SPEED) -
		full_conf->camera->fov.y * sin(-ROT_SPEED);
	full_conf->camera->fov.y = old_fov_x * sin(-ROT_SPEED) +
		full_conf->camera->fov.y * cos(-ROT_SPEED);
}

void	handle_cam_left(t_full_conf *full_conf)
{
	double old_dir_x;
	double old_fov_x;

	//check_active_key(full_conf);
	old_dir_x = full_conf->config->init_dir.x;
	old_fov_x = full_conf->camera->fov.x;
	full_conf->config->init_dir.x = full_conf->config->init_dir.x *
		cos(ROT_SPEED) - full_conf->config->init_dir.y * sin(ROT_SPEED);
	full_conf->config->init_dir.y = old_dir_x * sin(ROT_SPEED) +
		full_conf->config->init_dir.y * cos(ROT_SPEED);
	full_conf->camera->fov.x = full_conf->camera->fov.x * cos(ROT_SPEED) -
		full_conf->camera->fov.y * sin(ROT_SPEED);
	full_conf->camera->fov.y = old_fov_x * sin(ROT_SPEED) +
		full_conf->camera->fov.y * cos(ROT_SPEED);
}
