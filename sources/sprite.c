/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptisteboisset <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:36:42 by baptisteb         #+#    #+#             */
/*   Updated: 2020/01/24 17:58:09 by baptisteb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"
# define SCALE_SPRITE 1
# define VMOVE 64

static t_drw_spt init_draw_sprite(t_map_config *config, t_display *camera, t_dimension sprite_pos)
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
	param.spt_scr_x = (int)((config->resolution.x / 2) * (1 +
														  param.transform.x / param.transform.y));
	param.spt_dim.y = abs(((int)(config->resolution.y /
								 (param.transform.y))) / SCALE_SPRITE);
	return (param);
}

void define_spt_draw_w(t_map_config *config, t_drw_spt	*param)
{
	param->draw_start.y = -param->spt_dim.y / 2 + config->resolution.y / 2
	+ param->v_screen_move;
	param->draw_end.y = param->spt_dim.y / 2 + config->resolution.y / 2
	+ param->v_screen_move;
	param->draw_start.y = (param->draw_start.y < 0) ? 0 : param->draw_start.y;
	param->draw_end.y = (param->draw_end.y >=
						 config->resolution.y) ? config->resolution.y - 1 : param->draw_end.y;
}

void define_spt_draw_h(t_map_config *config, t_drw_spt	*param)
{
	param->spt_dim.x = abs(((int) (config->resolution.y /
								   (param->transform.y))) / SCALE_SPRITE);
	param->draw_start.x = -param->spt_dim.x / 2 + param->spt_scr_x;
	param->draw_end.x = param->spt_dim.x / 2 + param->spt_scr_x;
	param->draw_start.x = (param->draw_start.x < 0) ? 0 : param->draw_start.x;
	param->draw_end.x = (param->draw_end.x >=
						 config->resolution.x) ? config->resolution.x - 1 : param->draw_end.x;
}

static void is_sprite(t_map_config *config, t_display *camera,t_data *data, t_sprite_list *temp_sprt)
{
	define_spt_draw_w(config, &temp_sprt->param);
	define_spt_draw_h(config, &temp_sprt->param);
	draw_stripe(&temp_sprt->param, config, data);
	data->spt_info = temp_sprt->param;
}

static void sprite_loop(t_map_config *config, t_display *camera, t_data *data)
{
	int				sprite_count;
	int				i;
	t_sprite_list	*temp_sprt;
	
	i = 0;
	sprite_count = ft_sprt_lstsize(config->sprt_lst);
	temp_sprt = config->sprt_lst;
	while (i < sprite_count)
	{
		temp_sprt->param = init_draw_sprite(config, camera, temp_sprt->dimension);
		is_sprite(config, camera, data, temp_sprt);
		temp_sprt = temp_sprt->next;
		i++;
	}
}

void game_loop(t_map_config *config, t_display *camera,t_data *data)
{
	floor_sky_cast(config, camera, data);
	raycasting_loop(config, camera, data);
	sprite_loop(config, camera, data);
	if (config->save_img != 1)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_img, 0, 0);
	data->loop_count++;
}
