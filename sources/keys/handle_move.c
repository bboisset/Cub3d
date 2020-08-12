/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:36:12 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/12 12:45:47 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	handle_go_up(t_full_conf *full_conf)
{
	if (full_conf->config->map[(int)(full_conf->camera->pos.x +
		full_conf->config->init_dir.x *
		MOVESPEED)][(int)full_conf->camera->pos.y] - 48 == 0)
		full_conf->camera->pos.x += full_conf->config->init_dir.x * MOVESPEED;
	if (full_conf->config->map[(int)full_conf->camera->pos.x]
		[(int)(full_conf->camera->pos.y + full_conf->config->init_dir.y *
		MOVESPEED)] - 48 == 0)
		full_conf->camera->pos.y += full_conf->config->init_dir.y * MOVESPEED;
}

void	handle_go_down(t_full_conf *full_conf)
{
	if (full_conf->config->map[(int)(full_conf->camera->pos.x -
		full_conf->config->init_dir.x *
		MOVESPEED)][(int)full_conf->camera->pos.y] - 48 == 0)
		full_conf->camera->pos.x -= full_conf->config->init_dir.x * MOVESPEED;
	if (full_conf->config->map[(int)full_conf->camera->pos.x]
	[(int)(full_conf->camera->pos.y - full_conf->config->init_dir.y *
	MOVESPEED)] - 48 == 0)
		full_conf->camera->pos.y -= full_conf->config->init_dir.y * MOVESPEED;
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
}
