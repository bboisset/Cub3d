/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:51:44 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/03 23:26:26 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	end_of_line(char *temp)
{
	int i;

	i = 0;
	if (temp)
		while (temp[i] != '\0')
		{
			if (temp[i++] == '\n')
				return (i);
		}
	return (0);
}

int	exit_fct(char **temp, char **buffer)
{
	free(*temp);
	free(*buffer);
	return (-1);
}

int	store_rest(char *temp, char **rest)
{
	int i;
	int j;
	int temp_len;

	j = 0;
	i = 0;
	temp_len = ft_gnl_strlen(temp);
	while (temp[i] != '\0')
		if (temp[i++] == '\n')
		{
			j++;
			if (j > 0)
			{
				free(*rest);
				*rest = (ft_gnl_substr(temp, i, temp_len));
				if (!rest)
					return (0);
				return (1);
			}
		}
	return (1);
}

int	read_line(int const fd, char **line, char **rest)
{
	char		*buffer;
	char		*temp;
	ssize_t		res;

	temp = ft_gnl_strdup(*rest);
	res = 1;
	if (!temp || !(buffer = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	while (end_of_line(temp) == 0 &&
	((res = read(fd, buffer, BUFFER_SIZE)) != 0))
	{
		if (res < 0)
			return (exit_fct(&temp, &buffer));
		buffer[res] = '\0';
		if (!(temp = ft_gnl_strjoin(temp, buffer)))
			return (exit_fct(&temp, &buffer));
	}
	*line = ft_gnl_substr(temp, 0, end_of_line(temp) - 1);
	if (!line || !(store_rest(temp, rest)))
		return (exit_fct(&temp, &buffer));
	free(buffer);
	free(temp);
	if (res <= 0 && end_of_line(*rest) == 0)
		return (0);
	return (1);
}

int	get_next_line(int const fd, char **line)
{
	static char	*rest;
	int			res;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	res = read_line(fd, line, &rest);
	if (res == 0 || res == -1)
	{
		if (rest)
			free(rest);
		rest = NULL;
	}
	return (res);
}
