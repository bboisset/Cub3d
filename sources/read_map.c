/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:57:42 by baptisteb         #+#    #+#             */
/*   Updated: 2020/08/03 21:44:09 by bboisset         ###   ########.fr       */
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

static int	create_temp_map(t_map_config *config, char ***temp_map)
{
	int		i;
	int		j;
	char	**ptr_temp_map;
	t_list	*temp_lst;

	i = 0;
	ptr_temp_map = *temp_map;
	temp_lst = config->temp_map;
	while (i < config->map_w.y)
	{
		if (!(ptr_temp_map[i] = malloc(sizeof(char) * (config->map_w.x + 1))))
			return (-1);
		ft_strcpy(ptr_temp_map[i], temp_lst->content);
		j = ft_strlen(temp_lst->content);
		while (j < config->map_w.x)
			ptr_temp_map[i][j++] = '1';
		ptr_temp_map[i][j] = '\0';
		temp_lst = temp_lst->next;
		i++;
	}
	ft_lstfree(&config->temp_map);
	return (0);
}

static int	switch_temp_to_map(t_map_config *config, char ***temp_map)
{
	int		i;
	int		j;
	int		k;
	char	**ptr_temp_map;

	i = 0;
	k = 0;
	ptr_temp_map = *temp_map;
	while (i < config->map_w.x)
	{
		j = 0;
		if (!(config->map[i] = malloc(sizeof(char) * (config->map_w.y + 1))))
			return (temp_map_switcher_error(config->map, i, ptr_temp_map));
		while (j < config->map_w.y)
		{
			config->map[i][j] = ptr_temp_map[j][i];
			j++;
		}
		i++;
	}
	while (k < config->map_w.y)
		free(ptr_temp_map[k++]);
	free(ptr_temp_map);
	return (0);
}

/*
** Define map Height; Allocate a string of map width length for transfer data
*/

int			read_map(char *str, t_map_config *config)
{
	char **temp_map;

	config->map_w.y = ft_lstsize(config->temp_map);
	if (!(config->map = malloc(sizeof(char*) * config->map_w.x)))
		return (-1);
	if (!(temp_map = malloc(sizeof(char*) * config->map_w.y)))
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
