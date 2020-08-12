/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_gun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:49:38 by baptisteb         #+#    #+#             */
/*   Updated: 2020/08/10 21:12:52 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/header.h"

void	sprite_in_front_loop(t_full_conf *full_conf)
{
	int				sprite_count;
	int				i;
	t_sprite_list	*temp_sprt;

	i = 0;
	sprite_count = ft_sprt_lstsize(full_conf->config->sprt_lst);
	temp_sprt = full_conf->config->sprt_lst;
	while (i < sprite_count)
	{
		sprite_in_front(full_conf, temp_sprt);
		temp_sprt = temp_sprt->next;
		i++;
	}
}

void	fire(t_full_conf *full_conf)
{
	if (full_conf->gun->ammo > 0)
	{
		full_conf->gun->ammo--;
		play_sound("./ressources/sounds/gun.wav", 0, full_conf);
		sprite_in_front_loop(full_conf);
		gun(full_conf, 0);
	}
}

void	gun_animation(t_full_conf *full_conf)
{
	full_conf->gun->gun_pos.x = full_conf->gun->call_count * 2;
	full_conf->gun->gun_pos.y = (pow(full_conf->gun->call_count, 2) * 0.5) - 40;
	if (full_conf->gun->call_count < 1)
		full_conf->gun->gun_pos.y * -1;
	if (full_conf->gun->direction == 1)
		full_conf->gun->call_count++;
	else
		full_conf->gun->call_count--;
	if (full_conf->gun->call_count <= -10)
		full_conf->gun->direction = 1;
	else if (full_conf->gun->call_count >= 10)
		full_conf->gun->direction = 0;
}

int		gun(t_full_conf *full_conf, int animation)
{
	if (animation)
		gun_animation(full_conf);
	mlx_put_image_to_window(full_conf->data->mlx_ptr, full_conf->data->mlx_win,
		full_conf->gun->img->temp,
		full_conf->config->res.x / 2 - full_conf->gun->gun_pos.x,
		full_conf->config->res.y - 190 - full_conf->gun->gun_pos.y);
	return (0);
}
