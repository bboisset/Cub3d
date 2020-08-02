/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_forms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:37:11 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/02 15:37:16 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void draw_circle(int x, int y, int r, t_img_data *img)
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

void draw_vertical_line(int x, int y1, int y2, const int color, t_data *data)
{
	int index;
	
	if (y1 < 0 || y2 < 0)
		return ;
	if (y2 < y1){
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

void draw_stripe_line_loop(int x, t_dimension tex_dim, t_drw_spt *param,
						   t_map_config *config, t_data *data)
{
	int y;
	int d;
	int index;
	int index_sprt;
	
	y = param->draw_start.y;
	//printf("o--%f--o\n     \n%f     %f\n     \no--%f--o\n\n\n",param->draw_start.y,param->draw_end.y,param->draw_start.x,param->draw_end.x);
	while (y < param->draw_end.y)
	{
		d = (y - param->v_screen_move) * 256 - config->resolution.y * 128 +
		param->spt_dim.y * 128;
		tex_dim.y = (int)((d * SPRITE_H) / param->spt_dim.y) / 256;
		index = (x * (data->data->bpp >> 3)) + (y * data->data->sizeline);
		index_sprt = ((int)tex_dim.x * config->textures->sprite_texture->bpp
					  >> 3) + ((int)tex_dim.y * config->textures->sprite_texture->sizeline);
		if (config->textures->sprite_texture->data_img[index_sprt] != 0 ||
			config->textures->sprite_texture->data_img[index_sprt + 1] != 0 ||
			config->textures->sprite_texture->data_img[index_sprt + 2] != 0)
		{
			ft_memcpy(&data->data->data_img[index],
					  &config->textures->sprite_texture->data_img[index_sprt], 3);
			ft_memcpy(&data->data->data_img[index + 1],
					  &config->textures->sprite_texture->data_img[index_sprt + 1], 3);
			ft_memcpy(&data->data->data_img[index + 2],
					  &config->textures->sprite_texture->data_img[index_sprt + 2], 3);
		}
		y++;
	}
}

void draw_stripe_line(int x, t_drw_spt *param, t_map_config *config, t_data *data)
{
	t_dimension tex_dim;
	
	tex_dim.x = (int)(256 * (x - (-param->spt_dim.x / 2 + param->spt_scr_x)) *
					  SPRITE_W / param->spt_dim.x) / 256;
	if (param->transform.y > 0 && x > 0 && x < config->resolution.x &&
		param->transform.y < config->ZBuffer[x])
	{
		draw_stripe_line_loop(x, tex_dim, param, config, data);
	}
}
void draw_stripe(t_drw_spt *param, t_map_config *config, t_data *data)
{
	int x;
	
	x = param->draw_start.x;
	config->textures->sprite_texture->data_img =
	mlx_get_data_addr(config->textures->sprite_texture->temp,
					  &config->textures->sprite_texture->bpp,
					  &config->textures->sprite_texture->sizeline,
					  &config->textures->sprite_texture->endian);
	while (x <  param->draw_end.x)
	{
		draw_stripe_line(x, param, config, data);
		x++;
	}
}
