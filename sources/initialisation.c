/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:53:49 by baptisteb         #+#    #+#             */
/*   Updated: 2020/08/04 13:00:03 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_img_data		*init_img_data(t_data *data)
{
	t_img_data	*img_data;

	if (!(img_data = (t_img_data*)malloc(sizeof(t_img_data))))
		return (NULL);
	img_data->data_img = mlx_get_data_addr(data->mlx_img, &img_data->bpp,
		&img_data->bpp, &img_data->endian);
	return (img_data);
}

static t_active_action	init_active_key(void)
{
	t_active_action	pressed_key;

	pressed_key.down_active = 0;
	pressed_key.up_active = 0;
	return (pressed_key);
}

t_data					*init_data(t_map_config *config)
{
	t_data *data;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	if ((data->mlx_ptr = mlx_init()) == NULL)
		return (NULL);
	if ((data->mlx_win = mlx_new_window(data->mlx_ptr, config->res.x,
		config->res.y, "Cub3D")) == NULL)
		return (NULL);
	if ((data->mlx_img = mlx_new_image(data->mlx_ptr, config->res.x,
		config->res.y)) == NULL)
		return (NULL);
	if (!(data->data = init_img_data(data)))
		return (NULL);
	data->loop_count = 0;
	return (data);
}

t_full_conf				*join_full_conf(t_display *display,
	t_map_config *config, t_data *data)
{
	t_full_conf	*full_conf;

	if (!(full_conf = (t_full_conf*)malloc(sizeof(t_full_conf))))
		return (NULL);
	full_conf->config = config;
	full_conf->camera = display;
	full_conf->data = data;
	full_conf->key = init_active_key();
	return (full_conf);
}
