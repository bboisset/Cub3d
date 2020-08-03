/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:35:49 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/03 21:22:22 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	free_sprites(t_sprite_list **sprt_lst)
{
	t_sprite_list	*sprt;
	t_sprite_list	*tmp;

	sprt = *sprt_lst;
	while (sprt != NULL)
	{
		tmp = sprt;
		sprt = tmp->next;
		free(tmp);
	}
}
