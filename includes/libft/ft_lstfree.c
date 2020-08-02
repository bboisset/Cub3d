/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:46:56 by bboisset          #+#    #+#             */
/*   Updated: 2019/12/12 15:47:19 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **a_list)
{
	t_list	*list;
	t_list	*temp;

	list = *a_list;
	while (list != NULL)
	{
		temp = list;
		list = temp->next;
		free(temp->content);
		free(temp);
	}
}
