//
//  assign_struct.c
//  Cube3d
//
//  Created by Boisset on 09/01/2020.
//  Copyright © 2020 Boisset. All rights reserved.
//

#include "../header.h"

char	*get_path(int start, char *str, t_map_config *config)
{
	int		i;
	char	*path;
	
	i = start;
	while (str[i] == ' ')
		i++;
	if (!(path = ft_substr(str, i, ft_strlen(str))))
	{
		config->config_error = -3;
		return (NULL);
	}
	if (open(path, O_RDONLY) < 0)
	{
		config->config_error = -8;
		return (NULL);
	}
	return (path);
}

int 	assign_sky(char *str, t_map_config *config)
{
	int i;
	
	i = 1;
	while (str[i] == ' ')
		i++;
	config->sky_color.red = ft_edit_atoi(str, i);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i++] != ',')
		return (-6);
	config->sky_color.green = ft_edit_atoi(str, i);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i++] != ',')
		return (-6);
	config->sky_color.blue = ft_edit_atoi(str, i);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i++] != '\0')
		return (-6);
	config->sky_color.integer = rgb_to_int(config->sky_color.red, config->sky_color.green, config->sky_color.blue);
	return (check_color(config->sky_color.red, config->sky_color.green, config->sky_color.blue));
}

int 	assign_ground(char *str, t_map_config *config)
{
	int i;
	
	i = 1;
	while (str[i] == ' ')
		i++;
	config->ground_color.red = ft_edit_atoi(str, i);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i++] != ',')
		return (-6);
	config->ground_color.green = ft_edit_atoi(str, i);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i++] != ',')
		return (-6);
	config->ground_color.blue = ft_edit_atoi(str, i);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i++] != '\0')
		return (-6);
	config->ground_color.integer = rgb_to_int(config->ground_color.red, config->ground_color.green, config->ground_color.blue);
	return (check_color(config->ground_color.red, config->ground_color.green, config->ground_color.blue));
}

int assign_resolutions(char *str, t_map_config *config)
{
	int i;
	
	i = 1;
	while (str[i] == ' ')
		i++;
	config->resolution.x = (double)ft_edit_atoi(str, i);
	while (ft_isdigit(str[i]))
		i++;
	config->resolution.y = (double)ft_edit_atoi(str, i);
	i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i++] != '\0')
		return (-6);
	config->resolution.x = config->resolution.x > SCREEN_MAX_W ? SCREEN_MAX_W : config->resolution.x;
	config->resolution.y = config->resolution.y > SCREEN_MAX_H ? SCREEN_MAX_H : config->resolution.y;
	return ((config->resolution.x > 0 && config->resolution.y > 0) ? 0 : -7);
}
