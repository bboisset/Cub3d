/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:48:51 by baptisteb         #+#    #+#             */
/*   Updated: 2020/08/03 22:03:39 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_img_data	get_text_by_oritentation(t_map_config *config)
{
	if (config->wall_dir == 'N')
		return (*config->textures->north_texture);
	else if (config->wall_dir == 'S')
		return (*config->textures->south_texture);
	else if (config->wall_dir == 'E')
		return (*config->textures->east_texture);
	else if (config->wall_dir == 'W')
		return (*config->textures->west_texture);
	return (*config->textures->north_texture);
}

/*
** Draw wall with texture. With given x0/y0 to given xMax/yMax
** Select texture to apply by player orientation N/S/E/W
*/

void		draw_texture(int x, int tex_x, t_full_conf *full_conf,
	t_raycast *param)
{
	int			y;
	int			texy;
	int			index;
	t_img_data	c_texture;

	c_texture = get_text_by_oritentation(full_conf->config);
	full_conf->data->data->data_img = mlx_get_data_addr(
	full_conf->data->mlx_img, &full_conf->data->data->bpp,
	&full_conf->data->data->sizeline, &full_conf->data->data->endian);
	y = param->draw.draw_start;
	while (y < param->draw.draw_end)
	{
		texy = fabs((((y * 256 - full_conf->config->res.y * 128 +
			param->line_height * 128) * TEXT_H) / param->line_height) / 256);
		index = y * full_conf->data->data->sizeline +
			(full_conf->data->data->bpp >> 3) * x;
		ft_memcpy(&full_conf->data->data->data_img[index],
			&c_texture.data_img[texy % TEXT_H * c_texture.sizeline +
			tex_x % TEXT_H * (c_texture.bpp >> 3)], sizeof(int));
		y++;
	}
}

void		fill_img(int x, int y, int color, t_img_data *img)
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
