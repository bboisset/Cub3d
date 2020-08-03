/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:55:41 by baptisteb         #+#    #+#             */
/*   Updated: 2020/08/03 20:13:55 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	check_active_key(t_full_conf *full_conf)
{
	if (full_conf->key.up_active == 1)
		handle_go_up(full_conf);
	else if (full_conf->key.down_active == 1)
		handle_go_down(full_conf);
}

void	enable_minimap(t_full_conf *full_conf)
{
	full_conf->config->minimap_on =
		(full_conf->config->minimap_on == 1) ? 0 : 1;
	if (full_conf->config->minimap_on)
		place_player(full_conf);
	else
		reload_scene(full_conf, 0);
}
