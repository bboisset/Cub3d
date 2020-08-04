/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:35:56 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/04 18:19:55 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int			main_error(int code)
{
	code_error(code);
	return (-1);
}

static void	free_textures_path(t_map_config *config)
{
	free(config->textures->north_texture_path);
	free(config->textures->south_texture_path);
	free(config->textures->west_texture_path);
	free(config->textures->east_texture_path);
	free(config->textures->sprite_texture_path);
}

void		free_textures(t_map_config *config, t_data *data)
{
	free_textures_path(config);
	if (config->textures->loaded_texture > 0)
		free_image(data->mlx_ptr, config->textures->north_texture);
	if (config->textures->loaded_texture > 1)
		free_image(data->mlx_ptr, config->textures->south_texture);
	if (config->textures->loaded_texture > 2)
		free_image(data->mlx_ptr, config->textures->east_texture);
	if (config->textures->loaded_texture > 3)
		free_image(data->mlx_ptr, config->textures->west_texture);
	if (config->textures->loaded_texture > 4)
		free_image(data->mlx_ptr, config->textures->sprite_texture);
	free(config->textures);
}

int			texture_error(t_map_config *config, t_data *data)
{
	free_textures(config, data);
	return (-1);
}

int			full_error(t_map_config *config, t_data *data, t_display *display,
	int code)
{
	free_config(config, data);
	free_data(data);
	free(display);
	code_error(code);
	return (-1);
}
