/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:36:49 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/05 11:48:26 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	contain_only_set(char *str, char *set)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (set[j])
		{
			if (set[j++] != str[i])
				return (0);
		}
		j = 0;
		i++;
	}
	return (1);
}

static int	compare_prev_and_next(char *prev, char *str)
{
	int i;

	i = ft_strlen(prev);
	if (i >= ft_strlen(str))
		return (1);
	return (contain_only_set(str + i, "1"));
}

int			check_map_wall(t_map_config *config)
{
	t_list	*temp_lst;
	t_list	*prev_list;

	temp_lst = config->temp_map;
	prev_list = NULL;
	while (temp_lst)
	{
		if (last_char_is_wall(temp_lst->content) == 0)
			return (0);
		if (!prev_list || temp_lst->next == NULL)
		{
			if (contain_only_set(temp_lst->content, "1") == 0)
				return (0);
		}
		else
		{
			if (compare_prev_and_next(prev_list->content,
				temp_lst->content) == 0)
				return (0);
		}
		prev_list = temp_lst;
		temp_lst = temp_lst->next;
	}
	return (1);
}
