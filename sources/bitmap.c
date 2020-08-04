/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:36:45 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/04 09:41:15 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	put_int_to_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

static int	get_color(int x, int y, t_img_data *data)
{
	int color;

	color = *(int *)(data->data_img + (4 * (int)data->dimension.x *
		((int)data->dimension.y - 1 - y) + (4 * x)));
	return (color);
}

static void	write_data(t_img_data *data, int fd)
{
	int	y;
	int x;
	int	color;

	y = 0;
	while (y < data->dimension.y)
	{
		x = 0;
		while (x < data->dimension.x)
		{
			color = get_color(x, y, data);
			write(fd, &color, 3);
			x++;
		}
		y++;
	}
}

static void	bitmap_header(int file_size, int fd, t_img_data *data)
{
	int				i;
	int				tmp;
	unsigned char	bmp_file_header[54];

	i = 0;
	while (i < 54)
		bmp_file_header[i++] = (unsigned char)0;
	bmp_file_header[0] = (unsigned char)'B';
	bmp_file_header[1] = (unsigned char)'M';
	put_int_to_char(bmp_file_header + 2, file_size);
	bmp_file_header[10] = (unsigned char)54;
	bmp_file_header[14] = (unsigned char)40;
	tmp = data->dimension.x;
	put_int_to_char(bmp_file_header + 18, tmp);
	tmp = data->dimension.y;
	put_int_to_char(bmp_file_header + 22, tmp);
	bmp_file_header[26] = (unsigned char)1;
	bmp_file_header[28] = (unsigned char)24;
	write(fd, bmp_file_header, 54);
}

int			create_bitmap(t_map_config *config, t_img_data *data)
{
	int	fd;
	int	file_size;

	if ((fd = open("./Cub3D.bmp", O_CREAT | O_RDWR, S_IRUSR)) < 0)
	{
		config->config_error = -11;
		return (-11);
	}
	data->dimension.x = config->res.x;
	data->dimension.y = config->res.y;
	file_size = 54 + (config->res.x * config->res.y) * 4;
	bitmap_header(file_size, fd, data);
	write_data(data, fd);
	close(fd);
	return (0);
}
