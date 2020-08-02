/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptisteboisset <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:49:38 by baptisteb         #+#    #+#             */
/*   Updated: 2020/01/24 17:50:27 by baptisteb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../sources/header.h"

void sprite_in_front_loop(t_display_config *display_config)
{
	int				sprite_count;
	int				i;
	t_sprite_list	*temp_sprt;
	
	i = 0;
	sprite_count = ft_sprt_lstsize(D_CONFIG->sprt_lst);
	temp_sprt = D_CONFIG->sprt_lst;
	while (i < sprite_count)
	{
		sprite_in_front(display_config, temp_sprt);
		temp_sprt = temp_sprt->next;
		i++;
	}
}

void fire(t_display_config *display_config)
{
	if (GUN->ammo > 0)
	{
		GUN->ammo--;
		play_sound("/Users/baptisteboisset/Desktop/cub3d/sound/gun.wav", 0);
		sprite_in_front_loop(display_config);
		gun(display_config, 0);
	}
}

void gun_animation_two(t_display_config *display_config)
{
	if (GUN->call_count == 5 || GUN->call_count == 6)
	{
		GUN->gun_pos.x = -4;
		GUN->gun_pos.y = 2;
	}
	else if (GUN->call_count == 7)
	{
		GUN->gun_pos.x = -8;
		GUN->gun_pos.y = 4;
	}
	else if (GUN->call_count == 8)
	{
		GUN->gun_pos.x = 0;
		GUN->gun_pos.y = 0;
		GUN->call_count = -1;
	}
	GUN->call_count++;
}

void gun_animation(t_display_config *display_config)
{
	if (GUN->call_count == 0 || GUN->call_count == 4)
	{
		GUN->gun_pos.x = 0;
		GUN->gun_pos.y = 0;
	}
	else if (GUN->call_count == 1 || GUN->call_count == 3)
	{
		GUN->gun_pos.x = 4;
		GUN->gun_pos.y = 2;
	}
	else if (GUN->call_count == 2)
	{
		GUN->gun_pos.x = 8;
		GUN->gun_pos.y = 4;
	}
	gun_animation_two(display_config);
}

int gun(t_display_config *display_config, int animation)
{
	if (animation)
		gun_animation(display_config);
	mlx_put_image_to_window(D_DATA->mlx_ptr, D_DATA->mlx_win, GUN->img->temp, 
		D_CONFIG->resolution.x / 2 - GUN->gun_pos.x,
		D_CONFIG->resolution.y - 190 - GUN->gun_pos.y);
	return (0);
}

