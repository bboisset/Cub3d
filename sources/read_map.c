/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptisteboisset <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:57:42 by baptisteb         #+#    #+#             */
/*   Updated: 2020/01/24 17:57:47 by baptisteb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fill_string(char *str, char c, int length)
{
	int i;
	
	i = 0;
	while (i < length)
		str[i++] = c;
}

/**
 * Parse chained list; Fill tmp string with data and wall if no data
 */
static int	create_temp_map(t_map_config *config, char ***temp_map)
{
	int 	i;
	int		j;
	char	**ptr_temp_map;
	t_list	*temp_lst;
	
	i = 0;
	ptr_temp_map = *temp_map;
	temp_lst = config->temp_map;
	while (i < config->map_width.y)
	{
		if (!(ptr_temp_map[i] = malloc(sizeof(char) * (config->map_width.x + 1))))
			return (-1);
		ft_strcpy(ptr_temp_map[i], temp_lst->content);
		j = ft_strlen(temp_lst->content);
		while (j < config->map_width.x)
			ptr_temp_map[i][j++] = '1';
		ptr_temp_map[i][j] = '\0';
		free(temp_lst->content);
		temp_lst = temp_lst->next;
		i++;
	}
	return (0);
}

static int switch_temp_to_map(t_map_config *config, char ***temp_map)
{
	int		i;
	int		j;
	char	**ptr_temp_map;
	
	i = 0;
	ptr_temp_map = *temp_map;
	while (i < config->map_width.x)
	{
		j = 0;
		if (!(MAP[i] = malloc(sizeof(char) * (config->map_width.y + 1))))
			return (temp_map_switcher_error(MAP, i, ptr_temp_map));
		while (j < config->map_width.y)
		{
			MAP[i][j] = ptr_temp_map[j][i];
			j++;
		}
		i++;
	}
	free(ptr_temp_map);
	return (0);
}

/**
 * Define map Height; Allocate a string of map width length for transfer data
 */
int read_map(char *str, t_map_config *config)
{
	char **temp_map;
	
	config->map_width.y = ft_lstsize(config->temp_map);
	if (!(MAP = malloc(sizeof(char*) * config->map_width.x)) || !(temp_map = malloc(sizeof(char*) * config->map_width.y)))
		return (-1);
	config->step++;
	if ((create_temp_map(config, &temp_map) == -1))
		return (-1);
	config->step++;
	if ((switch_temp_to_map(config, &temp_map)) == -1)
		return (-1);
	config->step++;
	return (0);
}
