/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:06:45 by bboisset          #+#    #+#             */
/*   Updated: 2019/12/12 16:11:00 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *src)
{
	int		length;
	int		i;
	char	temp;

	length = ft_strlen(src);
	i = -1;
	while (++i < length / 2)
	{
		temp = src[i];
		src[i] = src[length - i - 1];
		src[length - i - 1] = temp;
	}
	return (src);
}
