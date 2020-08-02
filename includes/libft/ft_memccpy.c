/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:25:58 by bboisset          #+#    #+#             */
/*   Updated: 2019/10/15 18:21:36 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*m;
	unsigned char	*l;

	i = 0;
	m = (unsigned char*)dst;
	l = (unsigned char*)src;
	while (i < n)
	{
		m[i] = l[i];
		if (l[i++] == (unsigned char)c)
			return (m + i);
	}
	return (NULL);
}
