/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptisteboisset <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:56:20 by baptisteb         #+#    #+#             */
/*   Updated: 2020/01/24 17:56:47 by baptisteb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/header.h"

void fill_minimap_line(int vline_n, int color, t_display_config *display_config)
{
	int			x;
	int			index;
	int			old_color;
	
	old_color = color;
	x = 0;
	while (x < MINIMAP->y_width)//va trop loin
	{
		color = old_color;
		if (D_CONFIG->map[(int)floor(vline_n / MINIMAP->cub_sz)][(int)floor(x /
			MINIMAP->cub_sz)] - 48 == 1)
			color = 10330019;
		else if (D_CONFIG->map[(int)floor(vline_n / MINIMAP->cub_sz)][(int)floor(x /
			MINIMAP->cub_sz)] - 48 == 2)
			color = 65280;
		index = x * display_config->minimap->data->sizeline + 
			(display_config->minimap->data->bpp >> 3) * vline_n;
		ft_memcpy(&display_config->minimap->data->data_img[index], &color, 
			sizeof(int));
		x++;
	}
}

void place_player(t_display_config *display_config)
{
	int x;
	int y;
	
	if (!D_CONFIG->minimap_on)
		return ;
	x = MINIMAP->cub_sz * D_CAM->pos.x;
	y = MINIMAP->cub_sz * D_CAM->pos.y;
	mlx_put_image_to_window(D_DATA->mlx_ptr, D_DATA->mlx_win,
		MINIMAP->data->temp, 0, 0);
	mlx_put_image_to_window(D_DATA->mlx_ptr, D_DATA->mlx_win,
		MINIMAP->player_icon->temp, x, y);
}

static void fill_minimap(t_display_config *display_config)
{
	int line_n;
	int color;
	
	color = (235 << 24) + (64 << 16) + (52 << 8) + (0.34);
	line_n = 0;
	while (line_n < MINIMAP->x_width)
	{
		fill_minimap_line(line_n, color, display_config);
		line_n++;
	}
}

int mimimap(t_display_config *display_config)
{
	if (init_minimap(display_config) == -1)
		return (-3);
	if (init_icon_player(display_config) == -1)
	{
		free_minimap(MINIMAP, 0);
		return (-3);
	}
	fill_minimap(display_config);
	return (0);
}
