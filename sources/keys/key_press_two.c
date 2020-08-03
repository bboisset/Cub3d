/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:55:41 by baptisteb         #+#    #+#             */
/*   Updated: 2020/08/03 17:37:15 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	check_active_key(t_display_config *display_config)
{
	if (display_config->key.up_active == 1)
		handle_go_up(display_config);
	else if (display_config->key.down_active == 1)
		handle_go_down(display_config);
}

void	enable_minimap(t_display_config *display_config)
{
	D_CONFIG->minimap_on = (D_CONFIG->minimap_on == 1) ? 0 : 1;
	if (D_CONFIG->minimap_on)
		place_player(display_config);
	else
		reload_scene(display_config, 0);
}
