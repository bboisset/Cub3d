/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:37:31 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/03 22:10:16 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_dimension	get_step(t_raycast *param, t_display *cam)
{
	t_dimension step;

	if (cam->dir.x < 0)
	{
		step.x = -1;
		param->side_dist_x = (cam->pos.x - param->map_x) * param->delta_dist_x;
	}
	else
	{
		step.x = 1;
		param->side_dist_x = (param->map_x + 1.0 - cam->pos.x) *
			param->delta_dist_x;
	}
	if (cam->dir.y < 0)
	{
		step.y = -1;
		param->side_dist_y = (cam->pos.y - param->map_y) * param->delta_dist_y;
	}
	else
	{
		step.y = 1;
		param->side_dist_y = (param->map_y + 1.0 - cam->pos.y) *
			param->delta_dist_y;
	}
	return (step);
}

int					loop_till_hit(int side, t_raycast *param, t_display *camera,
	t_map_config *config)
{
	int			hit;
	t_dimension	step;

	step = get_step(param, camera);
	hit = 0;
	while (hit == 0)
	{
		if (param->side_dist_x < param->side_dist_y)
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

int					define_text_x(int side, int x, t_full_conf *full_conf,
	t_raycast *param)
{
	double	wall_x;
	int		tex_x;

	if (side == 0)
		wall_x = full_conf->camera->pos.y + param->perp_wall_dist *
			full_conf->camera->dir.y;
	else
		wall_x = full_conf->camera->pos.x + param->perp_wall_dist *
			full_conf->camera->dir.x;
	wall_x -= floor((wall_x));
	full_conf->config->z_buffer[x] = param->perp_wall_dist;
	tex_x = wall_x * TEXT_W;
	if (side == 0 && full_conf->camera->dir.x > 0)
		tex_x = TEXT_W - tex_x - 1;
	if (side == 1 && full_conf->camera->dir.y < 0)
		tex_x = TEXT_W - tex_x - 1;
	return (tex_x);
}

void				define_wall(t_full_conf *full_conf, int side,
	t_raycast *param)
{
	if (side == 1)
	{
		if (param->map_y < full_conf->camera->pos.y)
			full_conf->config->wall_dir = 'W';
		else
			full_conf->config->wall_dir = 'E';
	}
	else
	{
		if (param->map_x < full_conf->camera->pos.x)
			full_conf->config->wall_dir = 'N';
		else
			full_conf->config->wall_dir = 'S';
	}
}

int					raycasting_loop(t_full_conf *full_conf)
{
	int			x;
	int			side;
	int			tex_x;
	t_raycast	param;

	x = 0;
	while (x < full_conf->config->res.x)
	{
		init_raycast(x, &param, full_conf->camera, full_conf->config);
		side = wall_distance(&param, full_conf->camera, full_conf->config);
		define_draw(&param, full_conf->camera, full_conf->config);
		tex_x = define_text_x(side, x, full_conf, &param);
		define_wall(full_conf, side, &param);
		draw_texture(x, tex_x, full_conf, &param);
		x++;
	}
	return (0);
}
