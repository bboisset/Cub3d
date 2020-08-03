/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:56:59 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/03 18:59:45 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	first_launch_end(t_full_conf *full_conf)
{
	if (full_conf->config->save_img == 1)
	{
		if ((create_bitmap(full_conf->config, full_conf->data->data) < 0))
			return (-1);
	}
	else
	{
		gun(full_conf, 0);
		mlx_hook(full_conf->data->mlx_win, 2, 5, key_press, full_conf);
		mlx_hook(full_conf->data->mlx_win, 3, 5, key_realease, full_conf);
		mlx_hook(full_conf->data->mlx_win, 17, 0, handle_exit, full_conf);
		mlx_loop(full_conf->data->mlx_ptr);
	}
	return (0);
}

int first_launch(t_map_config	*config)
{
	t_data				*data;
	t_display			*camera;
	t_full_conf			*full_conf;

	if (check_map_wall(config) == 0)
		return map_error(config, 5);
	if ((read_map(NULL, config)) == -1)
		return (map_error(config, 3));
	if (!(data = init_data(config)))
		return (map_error(config, 3));
	if (!(camera = init_display(config)))
		return (cam_mall_err(config, data, 3));
	if (load_textures(config, data) == -1)
		return (full_error(config, data, camera, 3));
	if (!(full_conf = join_full_conf(camera, config, data)))
		return (full_error(config, data, camera, 3));
	if (!(config->z_buffer = malloc(config->res.x * sizeof(double))))
		return (full_error_d(full_conf, 0, 3));
	config->step++;
	if ((init_gun(full_conf)) < 0)
		return (full_error_d(full_conf, 1, 3));
	game_loop(full_conf);
	if (mimimap(full_conf) < 0)
		return (full_error_d(full_conf, 2, 3));
	if (first_launch_end(full_conf) == -1)
		return (full_error_d(full_conf, 2, 3));
	return (0);
}
