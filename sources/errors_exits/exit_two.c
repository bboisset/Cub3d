//
//  exit.c
//  Cube3d
//
//  Created by Boisset on 27/01/2020.
//  Copyright © 2020 Boisset. All rights reserved.
//

#include "../header.h"

void free_sprites(t_sprite_list **sprt_lst)
{
	t_sprite_list	*sprt;
	t_sprite_list	*tmp;
	
	sprt = *sprt_lst;
	while (sprt != NULL){
		tmp = sprt;
		sprt = tmp->next;
		free(tmp);
	}
}
