/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_cast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:49:09 by baptisteb         #+#    #+#             */
/*   Updated: 2020/08/03 22:05:28 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	floor_sky_cast(t_full_conf *full_conf)
{
	t_dimension	start_pos;
	int			middle_screen;

	start_pos.x = 0;
	middle_screen = full_conf->config->res.y / 2;
	while (start_pos.x < full_conf->config->res.x)
	{
		start_pos.y = 0;
		draw_vertical_line(start_pos, middle_screen,
			full_conf->config->sky_color.integer, full_conf->data);
		start_pos.y = middle_screen;
		draw_vertical_line(start_pos, full_conf->config->res.y,
			full_conf->config->ground_color.integer, full_conf->data);
		start_pos.x++;
	}
	return (0);
}
