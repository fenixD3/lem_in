//
// Created by Mort Deanne on 14/01/2020.
//

#include "../includes/lem_in.h"

#include <stdio.h>

int		set_depth(t_room *room, t_grp *grp)
{
	t_link	*link;
	int 	setted;

	link = room->link;
	setted = 0;
	while (link)
	{
		if ((link->room->depth == 0 && grp->start != link->room) ||
			link->room->depth > room->depth + 1)
		{
			link->room->depth = room->depth + 1;
			setted++;
		}
		link = link->next;
	}
	return (setted);
}

int wave(t_room *room, t_room *prev, int depth, t_grp *grp)
{
	t_link		*link;
	static int	setted;
	int 		tmp;

	if (room->depth == 0)
		setted = 0;
	if (!(tmp = set_depth(room, grp)) && depth == room->depth)
		return (0);
	setted += tmp;
	link = room->link;
	while (link)
	{
		if (link->room != prev && depth >= link->room->depth && link->room->depth > room->depth && link->room->way_number == 0)
			wave(link->room, room, depth, grp);
		link = link->next;
	}
	return (setted);
}

/*
** moon causes waves
*/

int		moon(t_grp *grp)
{
	int depth;

	depth = 0;
	while (grp->end->depth == 0)
	{
		if (depth == 3)
			depth = depth;
		if (!wave(grp->start, NULL, depth, grp))
			break ;
		depth++;
	}
	if (grp->end->depth != 0)
		return (1);
	else
		return (0);
}


void 	finding_ways(t_grp *grp)
{
	t_room *room;
	int tmp = 0;

	room = grp->start;
	room->depth = 0;

	while (moon(grp)) /// нужен контроль количестьва нагененрированных путей
	{
		while (set_and_go_back(grp->end, grp))
			;
		clear_nonwayed_nodes_depth(grp->room);
	}
}
