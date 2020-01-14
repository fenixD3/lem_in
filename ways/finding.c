//
// Created by Mort Deanne on 14/01/2020.
//

#include "../includes/lem_in.h"

#include <stdio.h>

_Bool	set_wave(t_room *room, t_room *end, int prev_depth, t_grp *grp)
{
	t_link *link;

	link = room->link;
	prev_depth++;
	while (link)
	{
		printf("%s\n", link->room->name);
		print_rooms_with_depth(grp->room);
		printf("--------------\n");
		if (end == link->room && link->room->depth != 0)
			return (1);
		if (link->room == grp->start)
			;
		else if (link->room->depth == 0 || link->room->depth > prev_depth)
		{
			link->room->depth = prev_depth;
			if (end == link->room)
				return (1);
		}
		else
			if(set_wave(link->room, end, prev_depth, grp))
				return (1);

		link = link->next;
	}
	return (0);
}

void 	finding_ways(t_grp *grp)
{
	t_room *room;


	room = grp->start;
	room->depth = 0;
	while (grp->end->depth == 0)
		set_wave(grp->start, grp->end, 0, grp);
	print_rooms_with_depth(grp->room);
}