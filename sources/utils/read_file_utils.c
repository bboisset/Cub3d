/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <bboisset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:06:05 by bboisset          #+#    #+#             */
/*   Updated: 2020/08/06 13:35:10 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	assign_map_width(char *str, t_map_config *config)
{
	int str_len;

	str_len = ft_strlen(str);
	if (!config->map_w.x || str_len > config->map_w.x)
		config->map_w.x = str_len;
}

int			char_is_sprite(char *str, int i, int map_y, t_map_config *config)
{
	t_sprite_list	*new_sprt_lst;

	if (!(new_sprt_lst = ft_sprt_lst_nw(get_post_wo_spaces(str, "2", i),
		map_y)))
		return (-3);
	ft_sprt_lst_back(&config->sprt_lst, new_sprt_lst);
	i++;
	return (i);
}

void		char_is_player(t_map_config *config, char *str, int i, int map_y)
{
	config->orientation = str[i];
	config->init_pos.x = get_post_wo_spaces(str, "NSEW", i) + 0.5;
	config->init_pos.y = map_y + 0.5;
	config->player_count++;
}

int			inspect_line_end(char *str, t_map_config *config)
{
	t_list	*new_list;

	if (!(new_list = ft_lstnew(ft_strtrim_all(str, " "))))
		return (-3);
	assign_map_width(new_list->content, config);
	ft_lstadd_back(&config->temp_map, new_list);
	config->step = 0;
	return (0);
}