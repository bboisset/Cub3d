/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:42:51 by bboisset          #+#    #+#             */
/*   Updated: 2019/12/12 16:17:16 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i] != '\0')
		if (c == set[i++])
			return (1);
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		to_rm;
	char	*str;

	i = 0;
	j = 0;
	to_rm = 0;
	while (is_in_set(s1[i + to_rm], set))
		to_rm++;
	while (s1[i] != '\0')
		i++;
	while (is_in_set(s1[i - 1], set) && i > to_rm)
		i--;
	j = i - to_rm;
	if (!(str = ft_calloc(j + 1, sizeof(char))))
		return (NULL);
	j--;
	i--;
	while (j + 1 > 0)
		str[j--] = s1[i--];
	return (str);
}
