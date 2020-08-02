#include "header.h"

//typedef struct			s_sprite_list
//{
//	t_dimension				dimension;
//	struct s_sprite_list	*next;
//}							t_sprite_list;


t_sprite_list	*ft_sprt_lst_nw(int x, int y)
{
	t_sprite_list	*new_sprt;
	
	if (!(new_sprt = (t_sprite_list*)malloc(sizeof(t_sprite_list))))
		return (NULL);
	if (!x || !y)
	{
		new_sprt->dimension.x = 0;
		new_sprt->dimension.y = 0;
	}
	else
	{
		new_sprt->dimension.x = x;
		new_sprt->dimension.y = y;
	}
	new_sprt->next = NULL;
	return (new_sprt);
}

void	ft_sprt_lst_back(t_sprite_list **a_sprt_lst, t_sprite_list *new)
{
	t_sprite_list	*temp;
	
	if (new)
	{
		if (*a_sprt_lst)
		{
			temp = *a_sprt_lst;
			while (temp->next)
				temp = temp->next;
			temp->next = new;
		}
		else
			*a_sprt_lst = new;
	}
}

int	ft_sprt_lstsize(t_sprite_list *lst)
{
	int i;
	
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

