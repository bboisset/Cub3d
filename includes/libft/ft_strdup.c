/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:45:42 by bboisset          #+#    #+#             */
/*   Updated: 2019/10/14 20:05:31 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*dest;

	s1_len = ft_strlen(s1);
	if (!(dest = (char *)malloc(sizeof(char) * s1_len + 1)))
		return (NULL);
	dest = ft_strcpy(dest, s1);
	return (dest);
}
