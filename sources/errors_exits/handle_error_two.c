/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:36:01 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/02 23:41:40 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int map_error(t_map_config	*config, int code)
{
	if (code == 1)
	{
		code = config->config_error != 0 ? config->config_error : 1;
		free_sprites(&config->sprt_lst);
	}
	free_config(config);
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
	free_config(config);
	free_data(data);
	code_error(code);
	return (-1);
}
