/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:19:13 by bboisset          #+#    #+#             */
/*   Updated: 2019/10/17 00:03:30 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*stock;

	i = 0;
	stock = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			stock = (char *)&s[i];
		i++;
	}
	if (s[i] == c)
		return ((char*)&s[i]);
	return (stock);
}
