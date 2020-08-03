/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastin_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:56:55 by baptisteb         #+#    #+#             */
/*   Updated: 2020/08/03 22:10:51 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fish_eye(int side, t_raycast *param, t_display *camera,
	t_dimension step)
{
	if (side == 0)
		param->perp_wall_dist = (param->map_x - camera->pos.x + (1 - step.x) /
			2) / camera->dir.x;
	else
		param->perp_wall_dist = (param->map_y - camera->pos.y + (1 - step.y) /
			2) / camera->dir.y;
}

int		wall_distance(t_raycast *param, t_display *camera, t_map_config *config)
{
	int side;

	side = 0;
	return (loop_till_hit(side, param, camera, config));
}

void	define_draw(t_raycast *param, t_display *camera, t_map_config *config)
{
	param->line_height = (int)(config->res.y / param->perp_wall_dist);
	param->draw.draw_start = -param->line_height / 2 + config->res.y
		/ 2;
	param->draw.draw_end = param->line_height / 2 + config->res.y / 2;
	param->draw.draw_start = (param->draw.draw_start <
		0) ? 0 : param->draw.draw_start;
	param->draw.draw_end = (param->draw.draw_end >=
		config->res.y) ? config->res.y - 1 : param->draw.draw_end;
}

void	init_raycast(int x, t_raycast *param, t_display *camera,
	t_map_config *config)
{
	param->camera_x = 2 * x / (double)config->res.x - 1;
	camera->dir.x = config->init_dir.x + camera->fov.x * param->camera_x;
	camera->dir.y = config->init_dir.y + camera->fov.y * param->camera_x;
	param->map_x = (int)camera->pos.x;
	param->map_y = (int)camera->pos.y;
	param->side_dist_x = 0;
	param->side_dist_y = 0;
	param->delta_dist_x = fabs(1 / camera->dir.x);
	param->delta_dist_y = fabs(1 / camera->dir.y);
	param->perp_wall_dist = 0;
}
