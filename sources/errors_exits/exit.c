/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:35:30 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/03 17:59:43 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void free_config(t_map_config *config)
{
	int i;
	
	i = 0;
	free_textures(config);
	free_sprites(&config->sprt_lst);
	if (config->step > 1)
	{
		if (config->step > 2)
			while (i < config->map_width.x)
				free(config->map[i++]);
		free(config->map);
		if (config->step > 3)
			free(config->z_buffer);
	}
	if (config->step >= 0 && config->step <= 2)
		ft_lstfree(&config->temp_map);
	free(config);
}

void free_gun(t_gun	*gun)
{
	free(gun->img->data_img);
	free(gun->img->temp);
	free(gun->img);
	free(gun);
}

void free_minimap(t_minimap *minimap, int type)
{
	if (type > 0)
	{
		free(minimap->player_icon->temp);
		free(minimap->player_icon->data_img);
		free(minimap->player_icon);
	}
	free(minimap->data->temp);
	free(minimap->data->data_img);
	free(minimap->data);
	free(minimap);
}

void free_data(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	free(data->mlx_img);
	free(data->data->data_img);
	free(data->data);
	free(data);
}

int exit_pr(t_display_config *display_config)
{
	free(D_CAM);
	free_config(D_CONFIG);
	free_data(D_DATA);
	free_minimap(MINIMAP, 1);
	free_gun(GUN);
	return (0);
}

