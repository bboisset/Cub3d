/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:54:31 by baptisteb         #+#    #+#             */
/*   Updated: 2020/08/03 17:43:50 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	reload_scene(t_display_config *display_config, int gun_anim)
{
	game_loop(display_config);
	place_player(display_config);
	gun(display_config, gun_anim);
}

int		handle_exit(t_display_config *display_config)
{
	system("killall afplay 2&>/dev/null >/dev/null\n");
	exit_pr(display_config);
	exit(1);
	return (0);
}

int		key_press(int keycode, t_display_config *display_config)
{
	if (keycode == 53)
	{
		handle_exit(display_config);
	}
	if (keycode == 13)
		handle_go_up(display_config);
	if (keycode == 1)
		handle_go_down(display_config);
	if (keycode == 0)
		handle_go_left(display_config);
	if (keycode == 2)
		handle_go_right(display_config);
	if (keycode == 124)
		handle_cam_right(display_config);
	if (keycode == 123)
		handle_cam_left(display_config);
	if (keycode == 46)
		enable_minimap(display_config);
	if (keycode == 49)
		fire(display_config);
	return (0);
}

int		key_realease(int keycode, t_display_config *display_config)
{
	if (keycode == 13)
		display_config->key.up_active = 0;
	if (keycode == 1)
		display_config->key.down_active = 0;
	return (0);
}
