/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_forms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:37:11 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/03 20:15:37 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		draw_circle(int x, int y, int r, t_img_data *img)
{
	int x1;
	int y1;
	int color;
	int index;
	int i;

	color = rgb_to_int(255, 0, 0);
	i = 0;
	while (i < 360)
	{
		x1 = r * cos(i * PI / 180);
		y1 = r * sin(i * PI / 180);
		index = (y + y1) * img->sizeline + (img->bpp >> 3) * (x + x1);
		ft_memcpy(&img->data_img[index], &color, sizeof(int));
		i++;
	}
}

void		draw_vertical_line(t_dimension start_pos, int y2,
	const int color, t_data *data)
{
	int index;
	int y1;
	int x;

	x = start_pos.x;
	y1 = start_pos.y;
	if (y1 < 0 || y2 < 0)
		return ;
	if (y2 < y1)
	{
		y1 += y2;
		y2 = y1 - y2;
		y1 -= y2;
	}
	data->data->data_img = mlx_get_data_addr(data->mlx_img, &data->data->bpp,
		&data->data->sizeline, &data->data->endian);
	while (y1 < y2)
	{
		index = y1 * data->data->sizeline + (data->data->bpp >> 3) * x;
		ft_memcpy(&data->data->data_img[index], &color, sizeof(int));
		y1++;
	}
}

void		draw_stripe_line_loop(int x, t_dimension tex_dim, t_drw_spt *param,
	t_full_conf *full_conf)
{
	int y;
	int d;
	int index;
	int index_sprt;

	y = param->draw_start.y;
	while (y < param->draw_end.y)
	{
		d = (y - param->v_screen_move) * 256 - full_conf->config->res.y * 128 +
			param->spt_dim.y * 128;
		tex_dim.y = (int)((d * SPRITE_H) / param->spt_dim.y) / 256;
		index = (x * (full_conf->data->data->bpp >> 3)) +
			(y * full_conf->data->data->sizeline);
		index_sprt = ((int)tex_dim.x *
		full_conf->config->textures->sprite_texture->bpp >> 3) + ((int)tex_dim.y
			* full_conf->config->textures->sprite_texture->sizeline);
		if (full_conf->config->textures->sprite_texture->data_img[index_sprt] !=
			0)
		{
			ft_memcpy(&full_conf->data->data->data_img[index],
			&full_conf->config->textures->sprite_texture->data_img[index_sprt],
			sizeof(int));
		}
		y++;
	}
}

static void	draw_stripe_line(int x, t_drw_spt *param,
	t_full_conf *full_conf)
{
	t_dimension tex_dim;

	tex_dim.x = (int)(256 * (x - (-param->spt_dim.x / 2 + param->spt_scr_x)) *
		SPRITE_W / param->spt_dim.x) / 256;
	if (param->transform.y > 0 && x > 0 && x < full_conf->config->res.x &&
		param->transform.y < full_conf->config->z_buffer[x])
	{
		draw_stripe_line_loop(x, tex_dim, param, full_conf);
	}
}

void		draw_stripe(t_drw_spt *param, t_full_conf *full_conf)
{
	int x;

	x = param->draw_start.x;
	full_conf->config->textures->sprite_texture->data_img =
		mlx_get_data_addr(full_conf->config->textures->sprite_texture->temp,
		&full_conf->config->textures->sprite_texture->bpp,
		&full_conf->config->textures->sprite_texture->sizeline,
		&full_conf->config->textures->sprite_texture->endian);
	while (x < param->draw_end.x)
	{
		draw_stripe_line(x, param, full_conf);
		x++;
	}
}
