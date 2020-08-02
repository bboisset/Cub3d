/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:36:01 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/02 15:36:02 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int map_error(t_map_config	*config, int code)
{
	if (code == 1)
	{
		code = config->config_error != 0 ? config->config_error : 1;
		free_sprites(&config->sprt_lst);
		ft_lstfree(&config->temp_map);
	}
	free(config);
	code_error(code);
	return (-1);
}

int temp_map_switcher_error(char **map, int i, char **ptr_temp_map)
{
	int j;
	
	j = 0;
	while (j < i - 1)
		free(map[j++]);
	free(map);
	free(ptr_temp_map);
	return (-1);
}

int cam_mall_err(t_map_config *config,t_data *data, int code)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	free(config);
	free(data);
	code_error(code);
	return (-1);
}
