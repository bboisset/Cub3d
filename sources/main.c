/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:56:04 by baptisteb         #+#    #+#             */
/*   Updated: 2020/08/06 15:13:12 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			read_argument(const char *argument, t_map_config *config)
{
	if (ft_strncmp(argument, "--save", ft_strlen(argument)) == 0)
	{
		config->save_img = 1;
		config->small_res = 1;
		return (0);
	}
	return (-1);
}

static int	check_extension(const char *str, char *ext, t_map_config *config)
{
	int	i;

	i = 0;
	while (str[i] != '.')
		i++;
	i++;
	if ((ft_strncmp(str + i, ext, ft_strlen(str + i))) == 0)
		return (1);
	config->config_error = 12;
	return (0);
}

int			main(int argc, const char *argv[])
{
	int					fd;
	int					res;
	int					launch_res;
	t_map_config		*config;

	if (!(config = init_config()))
		return (main_error(3));
	if (argc == 3)
		if (read_argument(argv[2], config) == -1)
			return (map_error(config, 0));
	if (argc == 2 || argc == 3)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (map_error(config, 1));
		if (!check_extension(argv[1], "cub", config))
			return (map_error(config, 1));
		if ((res = read_file(fd, config)) == -1)
			return (map_error(config, 1));
		if ((launch_res = first_launch(config)) != 0)
			return (launch_res);
	}
	else
		return (map_error(config, 2));
	return (0);
}
