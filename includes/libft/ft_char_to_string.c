/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:45:32 by bboisset          #+#    #+#             */
/*   Updated: 2019/12/12 15:46:11 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_char_to_string(char c)
{
	char	*dest;

	if (!(dest = malloc(sizeof(char) * 2)))
		return (NULL);
	dest[0] = c;
	dest[1] = '\0';
	return (dest);
}
