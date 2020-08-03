/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:36:12 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/03 19:16:38 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	handle_go_up(t_full_conf *full_conf)
{
	full_conf->key.up_active = 1;
	if (full_conf->config->map[(int)(full_conf->camera->pos.x +
		full_conf->config->init_dir.x *
		MOVESPEED)][(int)full_conf->camera->pos.y] - 48 == 0)
		full_conf->camera->pos.x += full_conf->config->init_dir.x * MOVESPEED;
	if (full_conf->config->map[(int)full_conf->camera->pos.x]
		[(int)(full_conf->camera->pos.y + full_conf->config->init_dir.y *
		MOVESPEED)] - 48 == 0)
		full_conf->camera->pos.y += full_conf->config->init_dir.y * MOVESPEED;
	mlx_destroy_image(full_conf->data->mlx_ptr, full_conf->data->mlx_img);
	full_conf->data->mlx_img = mlx_new_image(full_conf->data->mlx_ptr,
		full_conf->config->res.x, full_conf->config->res.y);
	reload_scene(full_conf, 1);
}

void	handle_go_down(t_full_conf *full_conf)
{
	full_conf->key.down_active = 1;
	if (full_conf->config->map[(int)(full_conf->camera->pos.x -
		full_conf->config->init_dir.x *
		MOVESPEED)][(int)full_conf->camera->pos.y] - 48 == 0)
		full_conf->camera->pos.x -= full_conf->config->init_dir.x * MOVESPEED;
	if (full_conf->config->map[(int)full_conf->camera->pos.x]
	[(int)(full_conf->camera->pos.y - full_conf->config->init_dir.y *
	MOVESPEED)] - 48 == 0)
		full_conf->camera->pos.y -= full_conf->config->init_dir.y * MOVESPEED;
	mlx_destroy_image(full_conf->data->mlx_ptr, full_conf->data->mlx_img);
	full_conf->data->mlx_img = mlx_new_image(full_conf->data->mlx_ptr,
		full_conf->config->res.x, full_conf->config->res.y);
	reload_scene(full_conf, 1);
}

void	handle_go_left(t_full_conf *full_conf)
{
	if (full_conf->config->map[(int)(full_conf->camera->pos.x -
		full_conf->camera->fov.x *
		MOVESPEEDSEC)][(int)full_conf->camera->pos.y] - 48 == 0)
		full_conf->camera->pos.x -= full_conf->camera->fov.x * MOVESPEED;
	if (full_conf->config->map[(int)full_conf->camera->pos.x]
		[(int)(full_conf->camera->pos.y - full_conf->camera->fov.y *
		MOVESPEEDSEC)] - 48 == 0)
		full_conf->camera->pos.y -= full_conf->camera->fov.y * MOVESPEED;
	mlx_destroy_image(full_conf->data->mlx_ptr, full_conf->data->mlx_img);
	full_conf->data->mlx_img = mlx_new_image(full_conf->data->mlx_ptr,
		full_conf->config->res.x, full_conf->config->res.y);
	reload_scene(full_conf, 1);
}

void	handle_go_right(t_full_conf *full_conf)
{
	if (full_conf->config->map[(int)(full_conf->camera->pos.x +
		full_conf->camera->fov.x * MOVESPEEDSEC)]
		[(int)full_conf->camera->pos.y] - 48 == 0)
		full_conf->camera->pos.x += full_conf->camera->fov.x * MOVESPEED;
	if (full_conf->config->map[(int)full_conf->camera->pos.x]
		[(int)(full_conf->camera->pos.y + full_conf->camera->fov.y *
		MOVESPEEDSEC)] - 48 == 0)
		full_conf->camera->pos.y += full_conf->camera->fov.y * MOVESPEED;
	mlx_destroy_image(full_conf->data->mlx_ptr, full_conf->data->mlx_img);
	full_conf->data->mlx_img = mlx_new_image(full_conf->data->mlx_ptr,
		full_conf->config->res.x, full_conf->config->res.y);
	reload_scene(full_conf, 1);
}
