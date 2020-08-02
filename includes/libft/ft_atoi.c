/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:17:00 by bboisset          #+#    #+#             */
/*   Updated: 2019/10/15 19:14:53 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\f' || c == '\r' ||
			c == '\v') ? 1 : 0;
}

int			ft_atoi(const char *str)
{
	int i;
	int negative;
	int number;

	i = 0;
	negative = 0;
	number = 0;
	if (str[0] == '\0')
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		negative = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) && str[i] != '\0')
		number = number * 10 + (str[i++] - '0');
	if (negative)
		number *= -1;
	return (number);
}
