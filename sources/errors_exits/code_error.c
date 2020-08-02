/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:35:23 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/02 15:35:25 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void code_error(int code)
{
	code = code < 0 ? code * -1 : code;
	ft_putstr("Error\n");
	if (code == 0)
		ft_putstr("Argument not handle\n");
	else if (code == 1)
		ft_putstr("Can't access map Or Wrong Configuration\n");
	else if (code == 2)
		ft_putstr("Missing Argument\n");
	else if (code == 3)
		ft_putstr("Not Enough Memory Avalaible To Run\n");
	else if (code == 4)
		ft_putstr("Too many player on map\n");
	else if (code == 5)
		ft_putstr("Map is not surround by wall\n");
	else if (code == 6)
		ft_putstr("Error in config file\n");
	else if (code == 7)
		ft_putstr("Error in config file : Resolution\n");
	else if (code == 8)
		ft_putstr("Error in config file : Can't accesss to file\n");
	else if (code == 9)
		ft_putstr("Error in config file : Color is out of range (0-255)\n");
	else if (code == 10)
		ft_putstr("Not Enough Memory Avalaible To Run Or Gun Config is wrong\n");
	else if (code == 11)
		ft_putstr("Can't save bitmap\n");
}
