/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:35:56 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/03 19:01:32 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int main_error(int code)
{
	code_error(code);
	return (-1);
}

void free_image(t_img_data *img_data)
{
	free(img_data->temp);
	free(img_data->data_img);
	free(img_data);
}

void free_textures(t_map_config	*config)
{
	free(config->textures->north_texture_path);
	free(config->textures->south_texture_path);
	free(config->textures->west_texture_path);
	free(config->textures->east_texture_path);
	free(config->textures->sprite_texture_path);
	if (config->textures->loaded_texture > 0)
		free_image(config->textures->north_texture);
	if (config->textures->loaded_texture > 1)
		free_image(config->textures->south_texture);
	if (config->textures->loaded_texture > 2)
		free_image(config->textures->east_texture);
	if (config->textures->loaded_texture > 3)
		free_image(config->textures->west_texture);
	if (config->textures->loaded_texture > 4)
		free_image(config->textures->sprite_texture);
	free(config->textures);
}

int texture_error(t_map_config	*config)
{
	free_textures(config);
	return (-1);
}

int full_error(t_map_config *config, t_data *data, t_display *display, int code)
{
	free_config(config);
	free_data(data);
	free(display);
	code_error(code);
	return (-1);
}

int full_error_d(t_full_conf *full_conf, int type, int code)
{
	if (type > 0)
		free_gun(full_conf->gun);
	if (type > 2)
		free_minimap(full_conf->minimap, 1);
	code = full_conf->config->config_error < 0 ? full_conf->config->config_error : code;
	full_error(full_conf->config, full_conf->data, full_conf->camera, code);
	free(full_conf);
	return (-1);
}
