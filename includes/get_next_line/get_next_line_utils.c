/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:08:04 by bboisset          #+#    #+#             */
/*   Updated: 2019/11/07 19:34:56 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int        ft_strlen_gnl(const char *s)
{
    int    i;
    
    i = 0;
    if (!s)
        return (0);
    while (s[i] != '\0')
        i++;
    return (i);
}


char    *ft_strcpy_gnl(char *dst, const char *src)
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

char    *ft_strdup_gnl(const char *s1)
{
    size_t    s1_len;
    char    *dest;
    
    s1_len = ft_strlen_gnl(s1);
    if (!(dest = (char *)malloc(sizeof(char) * s1_len + 1)))
        return (NULL);
    dest = ft_strcpy_gnl(dest, s1);
    return (dest);
}

char    *ft_strjoin_gnl(const char *s1,const char *s2)
{
	char    *new_str;
	int        i;
	int        j;
	
	i = 0;
	j = 0;
	new_str = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
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

char	*ft_substr_gnl(char const *s, size_t start, size_t len)
{
	char	*str2;
	size_t	i;
	size_t	s_len;
	
	s_len = (size_t)ft_strlen_gnl(s);
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

