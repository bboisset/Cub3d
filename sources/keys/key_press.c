/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:54:31 by baptisteb         #+#    #+#             */
/*   Updated: 2020/08/03 19:06:31 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	reload_scene(t_full_conf *full_conf, int gun_anim)
{
	game_loop(full_conf);
	place_player(full_conf);
	gun(full_conf, gun_anim);
}

int		handle_exit(t_full_conf *full_conf)
{
	system("killall afplay 2&>/dev/null >/dev/null\n");
	exit_pr(full_conf);
	exit(1);
	return (0);
}

int		key_press(int keycode, t_full_conf *full_conf)
{
	if (keycode == 53)
	{
		handle_exit(full_conf);
	}
	if (keycode == 13)
		handle_go_up(full_conf);
	if (keycode == 1)
		handle_go_down(full_conf);
	if (keycode == 0)
		handle_go_left(full_conf);
	if (keycode == 2)
		handle_go_right(full_conf);
	if (keycode == 124)
		handle_cam_right(full_conf);
	if (keycode == 123)
		handle_cam_left(full_conf);
	if (keycode == 46)
		enable_minimap(full_conf);
	if (keycode == 49)
		fire(full_conf);
	return (0);
}

int		key_realease(int keycode, t_full_conf *full_conf)
{
	if (keycode == 13)
		full_conf->key.up_active = 0;
	if (keycode == 1)
		full_conf->key.down_active = 0;
	return (0);
}
