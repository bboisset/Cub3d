/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:38:28 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/02 16:14:02 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../sources/header.h"

int init_gun(t_display_config *display_config)
{
	void *img_ptr;
	int w;
	int h;
	
	w = 320;
	h = 200;
	if (open("/Users/baptisteboisset/Desktop/cub3d/srcs/imgs/gun3.xpm", O_RDONLY) < 0 ||
		!(GUN = (t_gun*)malloc(sizeof(t_gun))))
	{
		D_CONFIG->config_error = -10;
		return (-10);
	}
	img_ptr = mlx_xpm_file_to_image(D_DATA->mlx_ptr, "/Users/baptisteboisset/Desktop/cub3d/srcs/imgs/gun3.xpm",
									&w, &h);
	if (!img_ptr || !(GUN->img = load_textures_struct(img_ptr, NULL)))
	{
		D_CONFIG->config_error = -3;
		return (-3);
	}
	GUN->gun_pos = init_dimensions();
	GUN->call_count = 0;
	GUN->ammo = 64;
	return (0);
}

int init_icon_player(t_display_config *display_config)
{
	void *icn_ptr;
	int color;
	
	color = (255 << 24) + (255 << 16) + (255 << 8) + (0.4);
	icn_ptr = mlx_new_image(D_DATA->mlx_ptr, MINIMAP->cub_sz, MINIMAP->cub_sz);
	if (!(MINIMAP->player_icon = load_textures_struct(icn_ptr, NULL)))
	{
		free(icn_ptr);
		return (-1);
	}
	fill_img(MINIMAP->cub_sz, MINIMAP->cub_sz, color, MINIMAP->player_icon);
	draw_circle(MINIMAP->cub_sz/3, MINIMAP->cub_sz/3, MINIMAP->cub_sz/3,
				MINIMAP->player_icon);
	return (0);
}

/**
 * Define Minimap width with 20% of screen width or screen height if map width is superior of map height
 * Define size of cube by minimap width/height divided by map width/height
 **/
static void init_minimap_width_or_height(t_display_config *display_config)
{
	if (D_CONFIG->map_width.x < D_CONFIG->map_width.y)
	{
		display_config->minimap->x_width = floor(D_CONFIG->resolution.x * 0.2);
		display_config->minimap->cub_sz = floor(display_config->minimap->x_width /
												D_CONFIG->map_width.x);
		display_config->minimap->x_width = display_config->minimap->cub_sz *
		D_CONFIG->map_width.x;
		display_config->minimap->y_width = display_config->minimap->cub_sz *
		D_CONFIG->map_width.y;
	}
	else
	{
		display_config->minimap->y_width = floor(D_CONFIG->resolution.y * 0.2);
		display_config->minimap->cub_sz = floor(display_config->minimap->y_width /
												D_CONFIG->map_width.y);
		display_config->minimap->y_width = floor(display_config->minimap->cub_sz *
												 D_CONFIG->map_width.y);
		display_config->minimap->x_width = floor(display_config->minimap->cub_sz *
												 D_CONFIG->map_width.x);
	}
}

int	init_minimap(t_display_config *display_config)
{
	void *img_ptr;
	
	if (!(MINIMAP = (t_minimap*)malloc(sizeof(t_minimap))))
		return (-1);
	init_minimap_width_or_height(display_config);
	img_ptr = mlx_new_image(D_DATA->mlx_ptr, MINIMAP->x_width,
							MINIMAP->y_width);
	if (!(display_config->minimap->data = load_textures_struct(img_ptr, NULL)))
	{
		free(MINIMAP);
		return (-1);
	}
	display_config->minimap->data->temp = img_ptr;
	return (0);
}
