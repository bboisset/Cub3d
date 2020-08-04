/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:35:30 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/04 18:26:15 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	free_config(t_map_config *config, t_data *data)
{
	int i;

	i = 0;
	free_textures(config, data);
	free_sprites(&config->sprt_lst);
	if (config->step > 1)
	{
		if (config->step > 2)
			while (i < config->map_w.x)
				free(config->map[i++]);
		free(config->map);
		if (config->step > 3)
			free(config->z_buffer);
	}
	if (config->step >= 0 && config->step <= 2)
		ft_lstfree(&config->temp_map);
	free(config);
}

void	free_gun(t_data *data, t_gun *gun)
{
	mlx_destroy_image(data->mlx_ptr, gun->img->temp);
	free(gun->img);
	free(gun);
}

void	free_minimap(t_data *data, t_minimap *minimap, int type)
{
	if (type > 0)
	{
		mlx_destroy_image(data->mlx_ptr, minimap->player_icon->temp);
		free(minimap->player_icon);
	}
	mlx_destroy_image(data->mlx_ptr, minimap->data->temp);
	free(minimap->data);
	free(minimap);
}

void	free_data(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	free(data->data);
	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	free(data);
}

int		exit_pr(t_full_conf *full_conf)
{
	free(full_conf->camera);
	free_config(full_conf->config, full_conf->data);
	free_minimap(full_conf->data, full_conf->minimap, 1);
	free_gun(full_conf->data, full_conf->gun);
	free_data(full_conf->data);
	return (0);
}
