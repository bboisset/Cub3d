/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:30:41 by bboisset          #+#    #+#             */
/*   Updated: 2019/10/17 21:15:11 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_length;

	i = 0;
	needle_length = ft_strlen(needle);
	if (needle_length == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == *needle && len - i >= needle_length &&
				ft_strncmp(&haystack[i], needle, needle_length) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
