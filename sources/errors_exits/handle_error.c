/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:35:56 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/02 18:19:45 by bboisset         ###   ########.fr       */
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
	free(TEXTURE->north_texture_path);
	free(TEXTURE->south_texture_path);
	free(TEXTURE->west_texture_path);
	free(TEXTURE->east_texture_path);
	free(TEXTURE->sprite_texture_path);
	if (TEXTURE->loadedTexture > 0)
		free_image(TEXTURE->north_texture);
	if (TEXTURE->loadedTexture > 1)
		free_image(TEXTURE->south_texture);
	if (TEXTURE->loadedTexture > 2)
		free_image(TEXTURE->east_texture);
	if (TEXTURE->loadedTexture > 3)
		free_image(TEXTURE->west_texture);
	if (TEXTURE->loadedTexture > 4)
		free_image(TEXTURE->sprite_texture);
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

int full_error_d(t_display_config *display_config, int type, int code)
{
	if (type > 0)
		free_gun(GUN);
	if (type > 2)
		free_minimap(MINIMAP, 1);
	code = D_CONFIG->config_error < 0 ? D_CONFIG->config_error : code;
	full_error(D_CONFIG, D_DATA, D_CAM, code);
	free(display_config);
	return (-1);
}
