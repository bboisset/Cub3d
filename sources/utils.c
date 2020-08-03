/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:58:17 by baptisteb         #+#    #+#             */
/*   Updated: 2020/08/03 21:45:36 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_edit_atoi(const char *str, int start)
{
	int	i;
	int	number;

	i = start;
	number = 0;
	if (str[0] == '\0')
		return (0);
	while (!ft_isdigit(str[i]))
	{
		if (str[i++] != ' ')
			return (-1);
	}
	while (ft_isdigit(str[i]) && str[i] != '\0')
		number = number * 10 + (str[i++] - '0');
	return (number);
}

char		*ft_strtrim_all(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		to_rm;
	char	*new_str;

	i = 0;
	j = 0;
	to_rm = 0;
	while (s1[i] != '\0')
	{
		if (is_in_set(s1[i], set))
			to_rm++;
		i++;
	}
	if (!(new_str = malloc((i - to_rm + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		if (!is_in_set(s1[i], set))
			new_str[j++] = s1[i];
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

/*
** Find last occurance in string, but remove spaces of count
** Max is the limit to search
*/

int			get_post_wo_spaces(char *str, char *set, int max)
{
	int i;
	int j;
	int res;

	i = 0;
	j = 0;
	res = -1;
	max += 1;
	while (str[i] != '\0' && i != max)
	{
		if (str[i] == ' ')
			i++;
		else if (is_in_set(str[i], set))
		{
			res = j++;
			i++;
		}
		else
		{
			i++;
			j++;
		}
	}
	return (res);
}

static void	define_direction_two(char c, t_map_config *config,
	t_display *camera)
{
	if (c == 'S')
	{
		config->init_dir.x = 0;
		config->init_dir.y = 1;
		camera->fov.x = 0.66;
		camera->fov.y = 0;
	}
	else if (c == 'E')
	{
		config->init_dir.x = 1;
		config->init_dir.y = 0;
		camera->fov.x = 0;
		camera->fov.y = -0.66;
	}
}

void		define_direction(char c, t_map_config *config, t_display *camera)
{
	if (c == 'N')
	{
		config->init_dir.x = 0;
		config->init_dir.y = -1;
		camera->fov.x = -0.66;
		camera->fov.y = 0;
	}
	else if (c == 'W')
	{
		config->init_dir.x = -1;
		config->init_dir.y = 0;
		camera->fov.x = 0;
		camera->fov.y = 0.66;
	}
	define_direction_two(c, config, camera);
}
