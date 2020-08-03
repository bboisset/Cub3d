/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilialisation_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:35:13 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/03 18:50:52 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_texture	*init_textures(void)
{
	t_texture		*textures;

	if (!(textures = (t_texture*)malloc(sizeof(t_texture))))
		return (NULL);
	textures->north_texture_path = NULL;
	textures->south_texture_path = NULL;
	textures->east_texture_path = NULL;
	textures->west_texture_path = NULL;
	textures->sprite_texture_path = NULL;
	textures->loaded_texture = 0;
	return (textures);
}

static t_rgb_color	init_rgb_color(void)
{
	t_rgb_color color;

	color.red = 0;
	color.green = 0;
	color.blue = 0;
	return (color);
}

t_dimension			init_dimensions(void)
{
	t_dimension		dimensions;

	dimensions.x = (double)0;
	dimensions.y = (double)0;
	return (dimensions);
}

t_map_config		*init_config(void)
{
	t_map_config	*new_config;

	if (!(new_config = (t_map_config*)malloc(sizeof(t_map_config))))
		return (NULL);
	new_config->res = init_dimensions();
	new_config->map_w = init_dimensions();
	new_config->init_dir = init_dimensions();
	new_config->init_pos = init_dimensions();
	new_config->textures = init_textures();
	new_config->ground_color = init_rgb_color();
	new_config->sky_color = init_rgb_color();
	new_config->config_error = 0;
	new_config->minimap_on = 0;
	new_config->save_img = 0;
	new_config->step = -1;
	new_config->player_count = 0;
	new_config->temp_map = NULL;
	new_config->sprt_lst = NULL;
	return (new_config);
}

t_display			*init_display(t_map_config *config)
{
	t_display *display;

	if (!(display = (t_display*)malloc(sizeof(t_display))))
		return (NULL);
	display->fov = init_dimensions();
	display->fov.x = 0;
	display->fov.y = 0.66;
	define_direction(config->orientation, config, display);
	display->orientation = 0;
	display->dir = init_dimensions();
	display->pos = init_dimensions();
	display->pos.x = config->init_pos.x;
	display->pos.y = config->init_pos.y;
	return (display);
}
