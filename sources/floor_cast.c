/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_cast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:49:09 by baptisteb         #+#    #+#             */
/*   Updated: 2020/08/03 16:30:30 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int floor_sky_cast(t_display_config *display_config)
{
	t_dimension start_pos;
	int middle_screen;

	start_pos.x = 0;
	middle_screen = D_CONFIG->resolution.y / 2;
	while (start_pos.x < D_CONFIG->resolution.x)
	{
		start_pos.y = 0;
		draw_vertical_line(start_pos, middle_screen, D_CONFIG->sky_color.integer,
			D_DATA);
		start_pos.y = middle_screen;
		draw_vertical_line(start_pos, D_CONFIG->resolution.y, 
			D_CONFIG->ground_color.integer, D_DATA);
		start_pos.x++;
	}
	return (0);
}
