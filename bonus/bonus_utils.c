/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:38:37 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/03 22:20:00 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/header.h"

void	play_sound(char *path, int volume, t_full_conf *full_conf)
{
	char	*cmd;
	pid_t	pid;

	pid = fork();
	if (volume == 0)
		cmd = ft_strjoin("afplay -v 0.1 ", path);
	else
		cmd = ft_strjoin("afplay -v 1.2 ", path);
	if (cmd == NULL)
	{
		code_error(3);
		handle_exit(full_conf);
	}
	if (pid == 0)
	{
		system("killall afplay 2&>/dev/null >/dev/null\n");
		system(cmd);
		exit(0);
	}
	free(cmd);
}

void	sprite_in_front(t_full_conf *full_conf, t_sprite_list *temp_sprt)
{
	t_dimension	pointer;

	pointer.x = full_conf->config->res.x / 1.8;
	pointer.y = full_conf->config->res.y / 1.4;
	if (pointer.x >= temp_sprt->param.draw_start.x && pointer.x <=
	temp_sprt->param.draw_end.x && pointer.y >= temp_sprt->param.draw_start.y &&
	pointer.y <= temp_sprt->param.draw_end.y)
	{
		play_sound("./ressources/sounds/barrel_explosion.mp3", 1, full_conf);
	}
	reload_scene(full_conf, 0);
}
