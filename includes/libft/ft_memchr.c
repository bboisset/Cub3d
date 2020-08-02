/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:35:20 by bboisset          #+#    #+#             */
/*   Updated: 2019/10/14 20:01:40 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*m;

	m = (unsigned char*)s;
	while (n-- > 0)
	{
		if (*m == (unsigned char)c)
			return (m);
		m++;
	}
	return (NULL);
}
