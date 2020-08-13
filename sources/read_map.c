/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:57:42 by baptisteb         #+#    #+#             */
/*   Updated: 2020/08/13 12:32:27 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		fill_string(char *str, char c, int length)
{
	int i;

	i = 0;
	while (i < length)
		str[i++] = c;
}

static int	create_map(t_map_config *config)
{
	int		i;
	int		j;
	t_list	*temp_lst;

	i = 0;
	temp_lst = config->temp_map;
	while (i < config->map_w.y)
	{
		if (!(config->map[i] = malloc(sizeof(char) * (config->map_w.x + 1))))
			return (-1);
		ft_strcpy(config->map[i], temp_lst->content);
		j = ft_strlen(temp_lst->content);
		while (j < config->map_w.x)
			config->map[i][j++] = '1';
		config->map[i][j] = '\0';
		temp_lst = temp_lst->next;
		i++;
	}
	ft_lstfree(&config->temp_map);
	return (0);
}

/*
** Define map Height; Allocate a string of map width length for transfer data
*/

int			read_map(char *str, t_map_config *config)
{
	config->map_w.y = ft_lstsize(config->temp_map);
	if (!(config->map = malloc(sizeof(char*) * config->map_w.y)))
		return (-1);
	config->step++;//1
	if ((create_map(config) == -1))
		return (-1);
	config->step++;//2
	return (0);
}
