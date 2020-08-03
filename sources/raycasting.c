/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:37:31 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/03 16:27:01 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_dimension	get_step(t_raycast *param, t_display *camera, t_map_config *config)
{
	t_dimension step;
	
	if (camera->dir.x < 0)
	{
		step.x = -1;
		param->sideDistX = (camera->pos.x - param->mapX) * param->deltaDistX;
	}
	else
	{
		step.x = 1;
		param->sideDistX = (param->mapX + 1.0 - camera->pos.x) * param->deltaDistX;
	}
	if (camera->dir.y < 0)
	{
		step.y = -1;
		param->sideDistY = (camera->pos.y - param->mapY) * param->deltaDistY;
	}
	else
	{
		step.y = 1;
		param->sideDistY = (param->mapY + 1.0 - camera->pos.y) * param->deltaDistY;
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
		if (param->sideDistX  < param->sideDistY)
		{
			param->sideDistX += param->deltaDistX;
			param->mapX += step.x;
			side = 0;
		}
		else
		{
			param->sideDistY += param->deltaDistY;
			param->mapY += step.y;
			side = 1;
		}
		if (config->map[param->mapX][param->mapY] - 48 == 1)
			hit = 1;
	}
	fish_eye(side, param, camera, step);
	return (side);
}

int define_text_x(int side, int x, t_map_config *config, t_display *camera, t_raycast *param)
{
	double	wallX;
	int		texX;
	
	if (side == 0)
		wallX = camera->pos.y + param->perpWallDist * camera->dir.y;
	else
		wallX = camera->pos.x + param->perpWallDist * camera->dir.x;
	wallX -= floor((wallX));
	config->ZBuffer[x] = param->perpWallDist;
	texX = wallX * TEXT_W;
	if(side == 0 && camera->dir.x > 0)
		texX = TEXT_W - texX - 1;
	if(side == 1 && camera->dir.y < 0)
		texX = TEXT_W - texX - 1;
	return (texX);
}

void define_wall(t_map_config *config, t_display *camera,t_data *data, int side, t_raycast *param)
{
	if (side == 1)
	{
		if (param->mapY < camera->pos.y)
			config->wall_dir = 'W';
		else
			config->wall_dir = 'E';
	}
	else
	{
		if (param->mapX < camera->pos.x)
			config->wall_dir = 'N';
		else
			config->wall_dir = 'S';
	}
}

int raycasting_loop(t_display_config *display_config)
{
	int x;
	int side;
	int texX;
	t_raycast param;

	x = 0;
	while (x < D_CONFIG->resolution.x)
	{
		init_raycast(x, &param, D_CAM, D_CONFIG);
		side = wall_distance(&param, D_CAM, D_CONFIG);
		define_draw(&param, D_CAM, D_CONFIG);
		texX = define_text_x(side, x, D_CONFIG, D_CAM, &param);
		define_wall(D_CONFIG, D_CAM, D_DATA, side, &param);
		draw_texture(x, texX, D_DATA, D_CONFIG, &param);
		x++;
	}
	return (0);
}
