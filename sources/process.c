/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:56:59 by bboisset          #+#    #+#             */
/*   Updated: 2022/07/03 18:25:07 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	save_game_first_image(t_full_conf *full_conf)
{
	int	res;

	game_loop(full_conf);
	res = create_bitmap(full_conf->config, full_conf->data->data);
	if (res < 0)
		code_error(11);
	handle_exit(full_conf);
	return (0);
}

static void	launch_game(t_full_conf *full_conf)
{
	mlx_hook(full_conf->data->mlx_win, 2, 1L << 0, key_press, full_conf);
	mlx_hook(full_conf->data->mlx_win, 3, 1L << 1, key_realease, full_conf);
	mlx_hook(full_conf->data->mlx_win, 17, 1l << 17,
		handle_exit, full_conf);
	mlx_loop_hook(full_conf->data->mlx_ptr, reload_scene, full_conf);
	mlx_loop(full_conf->data->mlx_ptr);
}

static int	first_launch_end(t_full_conf *full_conf)
{
	if (full_conf->config->small_res == 0)
		if (mimimap(full_conf) < 0)
			return (-1);
	if (full_conf->config->save_img == 1)
		return (save_game_first_image(full_conf));
	else
		launch_game(full_conf);
	return (0);
}

int			first_launch(t_map_config *config)
{
	t_data				*data;
	t_display			*camera;
	t_full_conf			*full_conf;

	if (check_map_wall(config) == 0)
		return (map_error(config, 5));
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
	if (full_conf->config->small_res == 0)
		if ((init_gun(full_conf)) < 0)
			return (full_error_d(full_conf, 0, 3));
	if (first_launch_end(full_conf) == -1)
		return (full_error_d(full_conf, 2, 3));
	return (0);
}

void		game_loop(t_full_conf *full_conf)
{
	if (full_conf->data->loop_count > 0)
	{
		mlx_destroy_image(full_conf->data->mlx_ptr, full_conf->data->mlx_img);
		full_conf->data->mlx_img = mlx_new_image(full_conf->data->mlx_ptr,
			full_conf->config->res.x, full_conf->config->res.y);
	}
	floor_sky_cast(full_conf);
	raycasting_loop(full_conf);
	sprite_loop(full_conf);
	if (full_conf->config->save_img != 1)
	{
		mlx_put_image_to_window(full_conf->data->mlx_ptr,
			full_conf->data->mlx_win,
			full_conf->data->mlx_img, 0, 0);
	}
	full_conf->data->loop_count++;
}