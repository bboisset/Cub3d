/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:38:28 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/04 13:17:22 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/header.h"

int			init_gun(t_full_conf *full_conf)
{
	void	*img_ptr;
	int		w;
	int		h;

	w = 320;
	h = 200;
	if (open("./ressources/imgs/gun3.xpm",
		O_RDONLY) < 0 || !(full_conf->gun = (t_gun*)malloc(sizeof(t_gun))))
	{
		full_conf->config->config_error = -10;
		return (-10);
	}
	img_ptr = mlx_xpm_file_to_image(full_conf->data->mlx_ptr,
		"./ressources/imgs/gun3.xpm", &w, &h);
	if (!img_ptr || !(full_conf->gun->img =
		load_textures_struct(img_ptr, NULL)))
	{
		full_conf->config->config_error = -3;
		return (-3);
	}
	full_conf->gun->gun_pos = init_dimensions();
	full_conf->gun->call_count = 0;
	full_conf->gun->ammo = 64;
	return (0);
}

int			init_icon_player(t_full_conf *full_conf)
{
	void		*icn_ptr;
	int			color;
	t_minimap	*minimap;

	minimap = full_conf->minimap;
	color = (255 << 24) + (255 << 16) + (255 << 8) + (0.4);
	icn_ptr = mlx_new_image(full_conf->data->mlx_ptr, minimap->cub_sz,
		minimap->cub_sz);
	if (!(full_conf->minimap->player_icon = load_textures_struct(icn_ptr,
		NULL)))
	{
		free(icn_ptr);
		return (-1);
	}
	fill_img(minimap->cub_sz, minimap->cub_sz, color, minimap->player_icon);
	draw_circle(minimap->cub_sz / 3, minimap->cub_sz / 3, minimap->cub_sz / 3,
		minimap->player_icon);
	return (0);
}

/*
** Define Minimap width with 20% of screen width or screen height if map width
** is superior of map height
** Define size of cube by minimap width/height divided by map width/height
*/

static void	init_minimap_width_or_height(t_full_conf *full_conf)
{
	if (full_conf->config->map_w.x < full_conf->config->map_w.y)
	{
		full_conf->minimap->dim.x = floor(full_conf->config->res.x * 0.2);
		full_conf->minimap->cub_sz = floor(full_conf->minimap->dim.x /
			full_conf->config->map_w.x);
		full_conf->minimap->dim.x = full_conf->minimap->cub_sz *
		full_conf->config->map_w.x;
		full_conf->minimap->dim.y = full_conf->minimap->cub_sz *
		full_conf->config->map_w.y;
	}
	else
	{
		full_conf->minimap->dim.y = floor(full_conf->config->res.y * 0.2);
		full_conf->minimap->cub_sz = floor(full_conf->minimap->dim.y /
			full_conf->config->map_w.y);
		full_conf->minimap->dim.y = floor(full_conf->minimap->cub_sz *
			full_conf->config->map_w.y);
		full_conf->minimap->dim.x = floor(full_conf->minimap->cub_sz *
			full_conf->config->map_w.x);
	}
}

int			init_minimap(t_full_conf *full_conf)
{
	void *img_ptr;

	if (!(full_conf->minimap = (t_minimap*)malloc(sizeof(t_minimap))))
		return (-1);
	init_minimap_width_or_height(full_conf);
	img_ptr = mlx_new_image(full_conf->data->mlx_ptr, full_conf->minimap->dim.x,
		full_conf->minimap->dim.y);
	if (!(full_conf->minimap->data = load_textures_struct(img_ptr, NULL)))
	{
		free(full_conf->minimap);
		return (-1);
	}
	full_conf->minimap->data->temp = img_ptr;
	return (0);
}
