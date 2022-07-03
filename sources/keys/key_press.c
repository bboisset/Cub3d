/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:54:31 by baptisteb         #+#    #+#             */
/*   Updated: 2020/08/13 19:54:09 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	handle_move(t_full_conf *full_conf)
{
	if (full_conf->key.up_active == 1)
		handle_go_up(full_conf);
	if (full_conf->key.down_active == 1)
		handle_go_down(full_conf);
	if (full_conf->key.left_active == 1)
		handle_go_left(full_conf);
	if (full_conf->key.right_active == 1)
		handle_go_right(full_conf);
	if (full_conf->key.arrow_r_active == 1)
		handle_cam_right(full_conf);
	if (full_conf->key.arrow_l_active == 1)
		handle_cam_left(full_conf);
	
	if (fmod(full_conf->camera->pos.y, 1) == 0)
		full_conf->camera->pos.y += 0.01;
	if (fmod(full_conf->camera->pos.x, 1) == 0)
		full_conf->camera->pos.x += 0.01;
}

int		is_moving(t_full_conf *full_conf)
{
	return full_conf->key.up_active == 1 || full_conf->key.down_active == 1 ||
		full_conf->key.left_active == 1 ||
		full_conf->key.right_active == 1 ? 1 : 0;
}

int		reload_scene(t_full_conf *full_conf)
{
	int	gun_anim;
	
	handle_move(full_conf);//destroy img before put new ?
	game_loop(full_conf);
	gun_anim = is_moving(full_conf);
	if (full_conf->config->small_res == 0)
	{
		place_player(full_conf);
		gun(full_conf, gun_anim);
	}
	return (0);
}

int		key_press(int keycode, t_full_conf *full_conf)
{
	//printf("%i\n",keycode);
	if (keycode == KEY_ESC)
	{
		handle_exit(full_conf);
	}
	if (keycode == KEY_W)
		full_conf->key.up_active = 1;//handle_go_up(full_conf);
	if (keycode == KEY_S)
		full_conf->key.down_active = 1;//handle_go_down(full_conf);
	if (keycode == KEY_A)
		full_conf->key.left_active = 1;//handle_go_left(full_conf);
	if (keycode == KEY_D)
		full_conf->key.right_active = 1;//handle_go_right(full_conf);
	if (keycode == KEY_ARR_RIGHT)
		full_conf->key.arrow_r_active = 1;//handle_cam_right(full_conf);
	if (keycode == KEY_ARR_LEFT)
		full_conf->key.arrow_l_active = 1;//handle_cam_left(full_conf);
	if (keycode == KEY_M && full_conf->config->small_res == 0)
		enable_minimap(full_conf);
	if (keycode == KEY_SPACE && full_conf->config->small_res == 0)
		fire(full_conf);
	return (0);
}

int		key_realease(int keycode, t_full_conf *full_conf)
{
	if (keycode == KEY_W)
		full_conf->key.up_active = 0;
	if (keycode == KEY_S)
		full_conf->key.down_active = 0;
	if (keycode == KEY_A)
		full_conf->key.left_active = 0;
	if (keycode == KEY_D)
		full_conf->key.right_active = 0;
	if (keycode == KEY_ARR_RIGHT)
		full_conf->key.arrow_r_active = 0;
	if (keycode == KEY_ARR_LEFT)
		full_conf->key.arrow_l_active = 0;
	return (0);
}
