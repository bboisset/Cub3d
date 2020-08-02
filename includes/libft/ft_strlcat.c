/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:04:23 by bboisset          #+#    #+#             */
/*   Updated: 2019/10/15 17:30:22 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t length;

	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	length = i;
	if (dstsize == 0)
		return (length + ft_strlen(src));
	while (src[i - length] && i < dstsize - 1)
	{
		dst[i] = src[i - length];
		i++;
	}
	if (length < dstsize)
		dst[i] = '\0';
	return (length + ft_strlen(src));
}
