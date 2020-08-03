/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:37:38 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/03 18:50:51 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	assign_map_width(char *str, t_map_config *config)
{
	int str_len;
	
	str_len = ft_strlen(str);
	if (!config->map_w.x || str_len > config->map_w.x)
		config->map_w.x = str_len;
}

static int inspect_line(char *str, int line_n, t_map_config *config, int map_start)
{
	int				i;
	char			*set;
	t_list			*new_list;
	t_sprite_list	*new_sprt_lst;
	
	i = 0;
	set = (line_n == 1) ? "1" : "012NSEW";
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] == '2')
		{
			if (!(new_sprt_lst = ft_sprt_lst_nw(get_post_wo_spaces(str,"2", i), line_n - map_start)))//selecting first occurence only
				return (-3);
			ft_sprt_lst_back(&config->sprt_lst, new_sprt_lst);
			i++;
		}
		else
		{
			if (is_in_set(str[i], "NSEW"))
			{
				config->orientation = str[i];
				config->init_pos.x = get_post_wo_spaces(str,"NSEW", i) + 0.5;
				config->init_pos.y = line_n - map_start + 0.5;
				str[i] = '0';
				config->player_count++;
			}
			if (!is_in_set(str[i++], set) || config->player_count > 1)
				return (-4);
		}
	}
	if (last_char_is_wall(str) == 0 || !(new_list = ft_lstnew(ft_strtrim_all(str," "))))
		return (-5);
	assign_map_width(new_list->content, config);
	ft_lstadd_back(&config->temp_map, new_list);
	return (0);
}

static int element_hub_two(char *str, int line_n, int res, t_map_config *config)
{
	if (str[0] == 'E' && str[1] == 'A')
		config->textures->east_texture_path = get_path(2, str, config);
	else if (str[0] == 'S' && str[1] != 'O')
		config->textures->sprite_texture_path = get_path(1, str, config);
	else if (str[0] == 'F')
		res = assign_sky(str, config);
	else if (str[0] == 'C')
		res = assign_ground(str, config);
	if (res < 0)
		config->config_error = res;
	if (config->config_error < 0)
		return (-1);
	return (res);
}

static int	element_hub(char *str, int line_n, t_map_config *config)
{
	static int	map_start = 0;
	int			res;
	
	res = 0;
	while (str[0] == ' ')
		str++;
	if (str[0] == '1' && !map_start)
		map_start = line_n;
	if (map_start)
		res = inspect_line(str, line_n, config, map_start);
	else if (str[0] == '\0')
		return (0);
	else if (str[0] == 'R')
		res = assign_resolutions(str, config);
	else if (str[0] == 'N' && str[1] == 'O')
		config->textures->north_texture_path = get_path(2, str, config);
	else if (str[0] == 'S' && str[1] == 'O')
		config->textures->south_texture_path = get_path(2, str, config);
	else if (str[0] == 'W' && str[1] == 'E')
		config->textures->west_texture_path = get_path(2, str, config);
	if (res < 0)
		config->config_error = res;
	return (element_hub_two(str, line_n, res, config));
}

int read_file(int fd, t_map_config *config)
{
	int 	fd_status;
	int 	line_n;
	int		res;
	char	*new_line;
	
	line_n = 0;
	fd_status = 1;
	while (fd_status == 1)
	{
		if ((fd_status = get_next_line(fd, &new_line)) == -1)
			return (-1);
		res = element_hub(new_line, line_n++, config);
		free(new_line);
		if (res == -1)
			return (-1);
	}
	if (fd_status == 0)
		config->step = 0;
	if (fd_status == -1 || config->player_count == 0)
		return (-1);
	return (0);
}
