/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:35:56 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/02 15:35:57 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int main_error(int code)
{
	code_error(code);
	return (-1);
}

void free_textures(t_map_config	*config)
{
	free(TEXTURE->north_texture_path);
	free(TEXTURE->south_texture_path);
	free(TEXTURE->west_texture_path);
	free(TEXTURE->east_texture_path);
	if (TEXTURE->loadedTexture > 0)
		free(TEXTURE->north_texture);
	else if (TEXTURE->loadedTexture > 1)
		free(TEXTURE->south_texture);
	else if (TEXTURE->loadedTexture > 2)
		free(TEXTURE->east_texture);
	else if (TEXTURE->loadedTexture > 3)
		free(TEXTURE->west_texture);
	else if (TEXTURE->loadedTexture > 4)
		free(TEXTURE->sprite_texture);
}

int texture_error(t_map_config	*config)
{
	free_textures(config);
	return (-1);
}

int full_error(t_map_config *config, t_data *data, t_display *display, int code)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	free_config(config);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	free(data->mlx_ptr);
	free(data->mlx_img);
	free(data->data->data_img);
	free(data->data);
	free(data);
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
