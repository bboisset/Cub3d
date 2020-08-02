/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastin_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptisteboisset <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:56:55 by baptisteb         #+#    #+#             */
/*   Updated: 2020/01/24 17:57:34 by baptisteb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void fish_eye(int side, t_raycast *param, t_display *camera, t_dimension step)
{
	if (side == 0)
		param->perpWallDist = (param->mapX - camera->pos.x + (1 - step.x) / 2)
			/ camera->dir.x;
	else
		param->perpWallDist = (param->mapY - camera->pos.y + (1 - step.y) / 2)
			/ camera->dir.y;
}

int wall_distance(t_raycast *param, t_display *camera, t_map_config *config)
{
	int side;
	
	side = 0;
	return (loop_till_hit(side, param, camera, config));
}

void define_draw(t_raycast *param, t_display *camera, t_map_config *config)
{
	param->line_height = (int)(config->resolution.y / param->perpWallDist);
	param->draw.draw_start = -param->line_height / 2 + config->resolution.y
		/ 2;
	param->draw.draw_end = param->line_height / 2 + config->resolution.y / 2;
	param->draw.draw_start = (param->draw.draw_start < 
		0) ? 0 : param->draw.draw_start;
	param->draw.draw_end = (param->draw.draw_end >= config->resolution.y) ? config->resolution.y - 1 : param->draw.draw_end;
}

void init_raycast(int x, t_raycast *param, t_display *camera, t_map_config *config)
{
	param->cameraX = 2 * x / (double)config->resolution.x - 1;
	camera->dir.x = config->init_dir.x + camera->fov.x * param->cameraX;
	camera->dir.y = config->init_dir.y + camera->fov.y * param->cameraX;
	
	param->mapX = (int)camera->pos.x;
	param->mapY = (int)camera->pos.y;
	
	param->sideDistX = 0;
	param->sideDistY = 0;
	
	param->deltaDistX = fabs(1 / camera->dir.x);
	param->deltaDistY = fabs(1 / camera->dir.y);
	param->perpWallDist = 0;
}
