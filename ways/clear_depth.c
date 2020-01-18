//
// Created by Mort Deanne on 18/01/2020.
//

#include "../includes/lem_in.h"

void clear_nonwayed_nodes_depth(t_room *room)
{
	while (room)
	{
		if (!room->way_number)
			room->depth = 0;
		room = room->next;
	}
}