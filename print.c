//
// Created by Mort Deanne on 14/01/2020.
//

#include "includes/lem_in.h"
#include <stdio.h>


void 	print_rooms(t_room *room)
{
	t_link *linkk;
	while (room)
	{
		linkk = room->link;
		printf("%s:  ", room->name);
		while(linkk)
		{
			printf("%s -> ", linkk->room->name);
			linkk = linkk->next;
		}
		printf("\n");
		room = room->next;
	}
}

void 	print_rooms_with_depth(t_room *room)
{
	t_link *linkk;
	while (room)
	{
		printf("%s : %d\n", room->name, room->depth);
		room = room->next;
	}
}