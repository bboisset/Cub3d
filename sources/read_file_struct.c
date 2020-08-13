/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:37:45 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/12 18:08:40 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_img_data	*load_textures_struct(void *img_ptr, t_map_config *config)
{
	t_img_data	*img_data;

	if (!(img_data = (t_img_data*)malloc(sizeof(t_img_data))) || !img_ptr)
		return (NULL);
	img_data->data_img = mlx_get_data_addr(img_ptr, &img_data->bpp,
		&img_data->sizeline, &img_data->endian);
	img_data->temp = img_ptr;
	if (config)
		config->textures->loaded_texture += 1;
	return (img_data);
}

static int	load_xpm(char *path, t_map_config *config, t_data *data,
	t_img_data **texture)
{
	int			w;
	void		*img_ptr;

	w = 256;
	if (open(path, O_RDONLY) < 0)
	{
		config->config_error = -8;
		return (-3);
	}
	img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path, &w, &w);
	if (!img_ptr)
		return (-3);
	*texture = load_textures_struct(img_ptr, config);
	if (!texture)
		return (-3);
	return (0);
}

int			load_textures(t_map_config *config, t_data *data)
{
	if ((load_xpm(config->textures->north_texture_path, config, data,
		&config->textures->north_texture)) < 0)
		return (-1);
	if ((load_xpm(config->textures->south_texture_path, config, data,
		&config->textures->south_texture)) < 0)
		return (-1);
	if ((load_xpm(config->textures->east_texture_path, config, data,
		&config->textures->east_texture)) < 0)
		return (-1);
	if ((load_xpm(config->textures->west_texture_path, config, data,
		&config->textures->west_texture)) < 0)
		return (-1);
	if ((load_xpm(config->textures->sprite_texture_path, config, data,
		&config->textures->sprite_texture)) < 0)
		return (-1);
	return (0);
}
