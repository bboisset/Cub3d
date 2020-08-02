/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:25:58 by bboisset          #+#    #+#             */
/*   Updated: 2019/10/14 19:48:21 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*m;
	char	*l;

	if (dst == NULL || src == NULL)
		return (dst);
	i = 0;
	m = (char*)dst;
	l = (char*)src;
	while (i < n)
	{
		m[i] = l[i];
		i++;
	}
	return (dst);
}
