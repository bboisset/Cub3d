/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:56:20 by baptisteb         #+#    #+#             */
/*   Updated: 2020/08/03 22:20:13 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/header.h"

void		fill_minimap_line(int vline_n, int color, t_full_conf *full_conf)
{
	int			x;
	int			index;
	int			old_color;

	old_color = color;
	x = 0;
	while (x < full_conf->minimap->dim.y)
	{
		color = old_color;
		if (full_conf->config->map[(int)floor(vline_n /
			full_conf->minimap->cub_sz)][(int)floor(x /
			full_conf->minimap->cub_sz)] - 48 == 1)
			color = 10330019;
		else if (full_conf->config->map[(int)floor(vline_n /
			full_conf->minimap->cub_sz)][(int)floor(x /
			full_conf->minimap->cub_sz)] - 48 == 2)
			color = 65280;
		index = x * full_conf->minimap->data->sizeline +
			(full_conf->minimap->data->bpp >> 3) * vline_n;
		ft_memcpy(&full_conf->minimap->data->data_img[index], &color,
			sizeof(int));
		x++;
	}
}

void		place_player(t_full_conf *full_conf)
{
	int x;
	int y;

	if (!full_conf->config->minimap_on)
		return ;
	x = full_conf->minimap->cub_sz * full_conf->camera->pos.x;
	y = full_conf->minimap->cub_sz * full_conf->camera->pos.y;
	mlx_put_image_to_window(full_conf->data->mlx_ptr,
		full_conf->data->mlx_win, full_conf->minimap->data->temp, 0, 0);
	mlx_put_image_to_window(full_conf->data->mlx_ptr,
		full_conf->data->mlx_win, full_conf->minimap->player_icon->temp, x, y);
}

static void	fill_minimap(t_full_conf *full_conf)
{
	int line_n;
	int color;

	color = (235 << 24) + (64 << 16) + (52 << 8) + (0.34);
	line_n = 0;
	while (line_n < full_conf->minimap->dim.x)
	{
		fill_minimap_line(line_n, color, full_conf);
		line_n++;
	}
}

int			mimimap(t_full_conf *full_conf)
{
	if (init_minimap(full_conf) == -1)
		return (-3);
	if (init_icon_player(full_conf) == -1)
	{
		free_minimap(full_conf->minimap, 0);
		return (-3);
	}
	fill_minimap(full_conf);
	return (0);
}
