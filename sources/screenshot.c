
#include "header.h"
/*
static void	int_to_char(int n, unsigned char *src)
{
	src[0] = (unsigned char)(n);
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}
static int	get_pixel(t_window *window, unsigned int x, unsigned int y)
{
	int	ptr;
	
	ptr = *(int*)(window->data
				  + (4 * (int)window->width * ((int)window->height - 1 - y))
				  + (4 * x));
	return ((ptr & 0xFF0000) | (ptr & 0x00FF00) | (ptr & 0x0000FF));
}

static void bpm_header(int fd, t_display_config *display_config, int filesize)
{
	int i;
	unsigned char data[54];
	
	i = -1;
	while (++i < 54)
		data[i] = 0;
	data[0] = (unsigned char)('B');
	data[1] = (unsigned char)('M');
	int_to_char(filesize, data + 2);
	data[10] = (unsigned char)(54);
	data[14] = (unsigned char)(40);
	int_to_char(display_config->config->resolution.x, data + 18);
	int_to_char(display_config->config->resolution.y, data + 22);
	data[26] = (unsigned char)(1);
	data[28] = (unsigned char)(24);
	write(fd, data, 54);
}

static void bpm_content(int fd, t_display_config *display_config, int pad)
{
	unsigned char	zero[3];
	unsigned int	i;
	unsigned int	j;
	int				color;
	
	i = -1;
	while (++i < 3)
		zero[i] = 0;
	i = 0;
	while (i < display_config->config->resolution.y)
	{
		j = 0;
		while (j < display_config->config->resolution.x)
		{
			color = get_pixel(D_DATA->mlx_win, j, i);
			write(fd, &color, 3);
			write(fd, &zero, pad);
			j++;
		}
		i++;
	}
}
*/
