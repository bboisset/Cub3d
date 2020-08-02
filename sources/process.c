#include "header.h"

static int	first_launch_end(t_display_config *display_config)
{
	if (D_CONFIG->save_img == 1)
	{
		if ((create_bitmap(D_CONFIG, D_DATA->data) < 0))
			return (-1);
	}
	else
	{
		gun(display_config, 0);
		mlx_hook(D_DATA->mlx_win, 2, 5, key_press, display_config);
		mlx_hook(D_DATA->mlx_win, 3, 5, key_realease, display_config);
		mlx_loop(D_DATA->mlx_ptr);
	}
	return (0);
}

int first_launch(t_map_config	*config)
{
	t_data				*data;
	t_display			*camera;
	t_display_config	*display_config;
	
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
	if (!(display_config = join_display_config(camera, config, data)))
		return (full_error(config, data, camera, 3));
	if (!(config->ZBuffer = malloc(config->resolution.x * sizeof(double))))
		return (full_error_d(display_config, 0, 3));
	config->step++;
	if ((init_gun(display_config)) == -1)
		return (full_error_d(display_config, 1, 3));
	game_loop(config, camera, data);
	if (mimimap(display_config) == -1)
		return (full_error_d(display_config, 2, 3));
	if (first_launch_end(display_config) == -1)
		return (full_error_d(display_config, 2, 3));
	return (0);
}
