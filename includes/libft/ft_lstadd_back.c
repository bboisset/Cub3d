/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:49:13 by bboisset          #+#    #+#             */
/*   Updated: 2019/12/12 15:50:35 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (new)
	{
		if (*alst)
		{
			temp = *alst;
			while (temp->next)
				temp = temp->next;
			temp->next = new;
		}
		else
			*alst = new;
	}
}
