/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:54:31 by baptisteb         #+#    #+#             */
/*   Updated: 2020/08/04 15:36:29 by bboisset         ###   ########.fr       */
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
	if (keycode == KEY_ESC)
	{
		handle_exit(full_conf);
	}
	if (keycode == KEY_W)
		handle_go_up(full_conf);
	if (keycode == KEY_S)
		handle_go_down(full_conf);
	if (keycode == KEY_A)
		handle_go_left(full_conf);
	if (keycode == KEY_D)
		handle_go_right(full_conf);
	if (keycode == KEY_ARR_RIGHT)
		handle_cam_right(full_conf);
	if (keycode == KEY_ARR_LEFT)
		handle_cam_left(full_conf);
	if (keycode == KEY_M)
		enable_minimap(full_conf);
	if (keycode == KEY_SPACE)
		fire(full_conf);
	return (0);
}

int		key_realease(int keycode, t_full_conf *full_conf)
{
	if (keycode == KEY_W)
		full_conf->key.up_active = 0;
	if (keycode == KEY_S)
		full_conf->key.down_active = 0;
	return (0);
}
