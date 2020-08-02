/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptisteboisset <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:56:04 by baptisteb         #+#    #+#             */
/*   Updated: 2020/01/24 17:56:12 by baptisteb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

int read_argument(const char *argument, t_map_config *config)
{
	if (ft_strncmp(argument, "-save", ft_strlen(argument)) == 0)
	{
		config->save_img = 1;
		return (0);
	}
	return (-1);
}

//check player count is 1

int main(int argc, const char * argv[]) {
	int					fd;
	int					res;
	int					launch_res;
	t_map_config 		*config;

	if (!(config = init_config()))
		return (main_error(3));
	argc = 2;
	argv[1] = "/Users/baptisteboisset/Desktop/cub3d/test.txt";
    if (argc > 2)
        if (read_argument(argv[2], config) == -1)
			return (map_error(config, 0));
    if (argc > 1)
	{
		if (!(fd = open(argv[1], O_RDONLY)) || (res = read_file(fd, config))
			!= -1)
		{
			if ((launch_res = first_launch(config)) != 0)
				return (launch_res);
		}
		else
			return (map_error(config, 1));
	}
    else
		return (map_error(config, 2));
    return (0);
}
