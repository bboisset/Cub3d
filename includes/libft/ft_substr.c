/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:07:30 by bboisset          #+#    #+#             */
/*   Updated: 2019/12/12 16:07:25 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*str2;
	size_t	i;
	size_t	s_len;

	s_len = (size_t)ft_strlen(s);
	start = (start > s_len ? s_len : start);
	len = (start + len > s_len) ? s_len - start : len;
	str2 = malloc((len + 1) * sizeof(char));
	if (!str2)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		str2[i] = s[start + i];
		++i;
	}
	str2[i] = '\0';
	return (str2);
}
