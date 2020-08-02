/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_cast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:49:09 by baptisteb         #+#    #+#             */
/*   Updated: 2020/08/02 15:37:18 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int floor_sky_cast(t_map_config *config, t_display *camera,t_data *data)
{
	int x;
	int middle_screen;
	
	x = 0;
	middle_screen = config->resolution.y / 2;
	while (x < config->resolution.x)
	{
		draw_vertical_line(x, 0, middle_screen, config->sky_color.integer,
			data);
		draw_vertical_line(x, middle_screen, config->resolution.y, 
			config->ground_color.integer, data);
		x++;
	}
	return (0);
}
