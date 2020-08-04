/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:08:04 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/03 23:25:51 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_gnl_strjoin(char *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = malloc((ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1) *
		sizeof(char));
	if (!new_str)
		return (NULL);
	if (s1)
		while (s1[j] != '\0')
			new_str[i++] = s1[j++];
	j = 0;
	if (s2)
		while (s2[j] != '\0')
			new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_gnl_substr(char const *s, size_t start, size_t len)
{
	char	*str2;
	size_t	i;
	size_t	s_len;

	s_len = (size_t)ft_gnl_strlen(s);
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

char	*ft_gnl_strcpy(char *dst, const char *src)
{
	size_t i;

	i = 0;
	if (src)
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_gnl_strdup(const char *s1)
{
	size_t	s1_len;
	char	*dest;

	s1_len = ft_gnl_strlen(s1);
	if (!(dest = (char *)malloc(sizeof(char) * s1_len + 1)))
		return (NULL);
	dest = ft_gnl_strcpy(dest, s1);
	return (dest);
}
