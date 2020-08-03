/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:36:42 by baptisteb         #+#    #+#             */
/*   Updated: 2020/08/03 23:24:02 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_drw_spt	init_draw_sprite(t_map_config *config, t_display *camera,
	t_dimension sprite_pos)
{
	t_drw_spt	param;

	param.sprite_co.x = sprite_pos.x - camera->pos.x + 0.5;
	param.sprite_co.y = sprite_pos.y - camera->pos.y + 0.5;
	param.inv_det = 1.0 / (camera->fov.x * config->init_dir.y -
		config->init_dir.x * camera->fov.y);
	param.transform.x = param.inv_det * (config->init_dir.y *
		param.sprite_co.x - config->init_dir.x * param.sprite_co.y);
	param.transform.y = param.inv_det * (-camera->fov.y *
		param.sprite_co.x + camera->fov.x * param.sprite_co.y);
	param.v_screen_move = (int)(VMOVE / param.transform.y);
	param.spt_scr_x = (int)((config->res.x / 2) * (1 +
		param.transform.x / param.transform.y));
	param.spt_dim.y = abs(((int)(config->res.y /
		(param.transform.y))) / SCALE_SPRITE);
	return (param);
}

void				define_spt_draw_w(t_map_config *config, t_drw_spt *param)
{
	param->draw_start.y = -param->spt_dim.y / 2 + config->res.y / 2
	+ param->v_screen_move;
	param->draw_end.y = param->spt_dim.y / 2 + config->res.y / 2
	+ param->v_screen_move;
	param->draw_start.y = (param->draw_start.y < 0) ? 0 : param->draw_start.y;
	param->draw_end.y = (param->draw_end.y >=
		config->res.y) ? config->res.y - 1 : param->draw_end.y;
}

void				define_spt_draw_h(t_map_config *config, t_drw_spt *param)
{
	param->spt_dim.x = abs(((int)(config->res.y /
		(param->transform.y))) / SCALE_SPRITE);
	param->draw_start.x = -param->spt_dim.x / 2 + param->spt_scr_x;
	param->draw_end.x = param->spt_dim.x / 2 + param->spt_scr_x;
	param->draw_start.x = (param->draw_start.x < 0) ? 0 : param->draw_start.x;
	param->draw_end.x = (param->draw_end.x >=
		config->res.x) ? config->res.x - 1 : param->draw_end.x;
}

static void			is_sprite(t_full_conf *full_conf, t_sprite_list *temp_sprt)
{
	define_spt_draw_w(full_conf->config, &temp_sprt->param);
	define_spt_draw_h(full_conf->config, &temp_sprt->param);
	draw_stripe(&temp_sprt->param, full_conf);
	full_conf->data->spt_info = temp_sprt->param;
}

void				sprite_loop(t_full_conf *full_conf)
{
	int				sprite_count;
	int				i;
	t_sprite_list	*temp_sprt;

	i = 0;
	sprite_count = ft_sprt_lstsize(full_conf->config->sprt_lst);
	temp_sprt = full_conf->config->sprt_lst;
	while (i < sprite_count)
	{
		temp_sprt->param = init_draw_sprite(full_conf->config,
			full_conf->camera, temp_sprt->dimension);
		is_sprite(full_conf, temp_sprt);
		temp_sprt = temp_sprt->next;
		i++;
	}
}
