/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptisteboisset <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:48:51 by baptisteb         #+#    #+#             */
/*   Updated: 2020/01/24 17:48:58 by baptisteb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"
#define PI 3.1415926535

t_img_data get_text_by_oritentation(t_map_config *config)
{
	if (config->wall_dir == 'N')
		return (*TEXTURE->north_texture);
	else if (config->wall_dir == 'S')
		return (*TEXTURE->south_texture);
	else if (config->wall_dir == 'E')
		return (*TEXTURE->east_texture);
	else if (config->wall_dir == 'W')
		return (*TEXTURE->west_texture);
	return (*TEXTURE->north_texture);
}

/**
 * Draw wall with texture. With given x0/y0 to given xMax/yMax
 * Select texture to apply by player orientation N/S/E/W
 */
void	draw_texture(int x, int texX, t_data *data, t_map_config *config,
t_raycast *param)
{
	int y;
	int texy;
	int index;
	t_img_data c_texture;
	
	c_texture = get_text_by_oritentation(config);
	data->data->data_img = mlx_get_data_addr(data->mlx_img, &data->data->bpp,
		&data->data->sizeline, &data->data->endian);
	y = param->draw.draw_start;
	while (y < param->draw.draw_end)
	{
		texy = fabs((((y * 256 - config->resolution.y * 128 +
			param->line_height * 128) * TEXT_H) / param->line_height) / 256);
		index = y * data->data->sizeline + (data->data->bpp >> 3) * x;
		ft_memcpy(&data->data->data_img[index],
			&c_texture.data_img[texy % TEXT_H *
			c_texture.sizeline + texX % TEXT_H *
			(c_texture.bpp >> 3)],3);
		y++;
	}
}

void fill_img(int x, int y, int color, t_img_data *img)
{
	int index;
	int x1;
	int y1;
	
	x1 = 0;
	while (x1 < x)
	{
		y1 = 0;
		while (y1 < x)
		{
			index = y1 * img->sizeline + (img->bpp >> 3) * x1;
			ft_memcpy(&img->data_img[index], &color, sizeof(int));
			y1++;
		}
		x1++;
	}
}
