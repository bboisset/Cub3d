/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partials.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:36:39 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/03 20:21:13 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	check_color(int red, int green, int blue)
{
	return (red >= 0 && red  <= 255 && green >= 0 && green <= 255 &&
		blue >= 0 && blue <= 255) ? 0 : -9;
}

int	rgb_to_int(int r, int g, int b)
{
	int c;

	c = r;
	c = (c << 8) | g;
	c = (c << 8) | b;
	return (c);
}

int	is_in_set(char c, const char *set)
{
	int i;

	i = 0;
	while (set[i] != '\0')
		if (c == set[i++])
			return (1);
	return (0);
}

int	last_char_is_wall(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (i > 0)
	{
		if (str[i] == '1')
			return (1);
		if (ft_isdigit(str[i]))
			return (0);
		i--;
	}
	return (0);
}
