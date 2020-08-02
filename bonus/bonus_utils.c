#include "../sources/header.h"

void play_sound(char *path, int volume)
{
	char *cmd;
	pid_t pid = fork();
	
	if (volume == 0 )
		cmd = ft_strjoin("afplay -v 0.1 ", path);
	else
		cmd = ft_strjoin("afplay -v 1.2 ", path);
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
		play_sound("/Users/baptisteboisset/Desktop/cub3d/sound/barrel_explosion.mp3", 1);
	}
	reload_scene(display_config, 0);
}
