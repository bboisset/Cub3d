/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:37:31 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/03 18:59:38 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_dimension	get_step(t_raycast *param, t_display *camera, t_map_config *config)
{
	t_dimension step;

	if (camera->dir.x < 0)
	{
		step.x = -1;
		param->side_dist_x = (camera->pos.x - param->map_x) * param->delta_dist_x;
	}
	else
	{
		step.x = 1;
		param->side_dist_x = (param->map_x + 1.0 - camera->pos.x) * param->delta_dist_x;
	}
	if (camera->dir.y < 0)
	{
		step.y = -1;
		param->side_dist_y = (camera->pos.y - param->map_y) * param->delta_dist_y;
	}
	else
	{
		step.y = 1;
		param->side_dist_y = (param->map_y + 1.0 - camera->pos.y) * param->delta_dist_y;
	}
	return (step);
}


int loop_till_hit(int side, t_raycast *param, t_display *camera, t_map_config *config)
{
	int hit;
	t_dimension step;

	step = get_step(param, camera, config);
	hit = 0;
	while (hit == 0)
	{
		if (param->side_dist_x  < param->side_dist_y)
		{
			param->side_dist_x += param->delta_dist_x;
			param->map_x += step.x;
			side = 0;
		}
		else
		{
			param->side_dist_y += param->delta_dist_y;
			param->map_y += step.y;
			side = 1;
		}
		if (config->map[param->map_x][param->map_y] - 48 == 1)
			hit = 1;
	}
	fish_eye(side, param, camera, step);
	return (side);
}

int define_text_x(int side, int x, t_map_config *config, t_display *camera, t_raycast *param)
{
	double	wallX;
	int		tex_x;

	if (side == 0)
		wallX = camera->pos.y + param->perp_wall_dist * camera->dir.y;
	else
		wallX = camera->pos.x + param->perp_wall_dist * camera->dir.x;
	wallX -= floor((wallX));
	config->z_buffer[x] = param->perp_wall_dist;
	tex_x = wallX * TEXT_W;
	if(side == 0 && camera->dir.x > 0)
		tex_x = TEXT_W - tex_x - 1;
	if(side == 1 && camera->dir.y < 0)
		tex_x = TEXT_W - tex_x - 1;
	return (tex_x);
}

void define_wall(t_map_config *config, t_display *camera,t_data *data, int side, t_raycast *param)
{
	if (side == 1)
	{
		if (param->map_y < camera->pos.y)
			config->wall_dir = 'W';
		else
			config->wall_dir = 'E';
	}
	else
	{
		if (param->map_x < camera->pos.x)
			config->wall_dir = 'N';
		else
			config->wall_dir = 'S';
	}
}

int raycasting_loop(t_full_conf *full_conf)
{
	int x;
	int side;
	int tex_x;
	t_raycast param;

	x = 0;
	while (x < full_conf->config->res.x)
	{
		init_raycast(x, &param, full_conf->camera, full_conf->config);
		side = wall_distance(&param, full_conf->camera, full_conf->config);
		define_draw(&param, full_conf->camera, full_conf->config);
		tex_x = define_text_x(side, x, full_conf->config, full_conf->camera,
			&param);
		define_wall(full_conf->config, full_conf->camera, full_conf->data, side,
			&param);
		draw_texture(x, tex_x, full_conf->data, full_conf->config, &param);
		x++;
	}
	return (0);
}
