/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:38:37 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/02 21:54:24 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/header.h"

void play_sound(char *path, int volume, t_display_config *display_config)
{
	char *cmd;
	pid_t pid = fork();
	
	if (volume == 0)
		cmd = ft_strjoin("afplay -v 0.1 ", path);
	else
		cmd = ft_strjoin("afplay -v 1.2 ", path);
	if (cmd == NULL)
	{
		code_error(3);
		handle_exit(display_config);
	}
	if (pid == 0) {
		system("killall afplay 2&>/dev/null >/dev/null\n");
		system(cmd);
		exit(0);
	}
	free(cmd);
}

void sprite_in_front(t_display_config *display_config, t_sprite_list *temp_sprt)
{
	t_dimension	pointer;
	
	pointer.x = D_CONFIG->resolution.x / 1.8;
	pointer.y = D_CONFIG->resolution.y / 1.4;
	if (pointer.x >= temp_sprt->param.draw_start.x && pointer.x <= temp_sprt->param.draw_end.x &&
		pointer.y >= temp_sprt->param.draw_start.y && pointer.y <= temp_sprt->param.draw_end.y)
	{
		play_sound("./ressources/sounds/barrel_explosion.mp3", 1, display_config);
	}
	reload_scene(display_config, 0);
}
