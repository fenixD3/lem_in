//
// Created by Mort Deanne on 14/01/2020.
//

#include "../includes/lem_in.h"

#include <stdio.h>
#include <stdbool.h>




int		give_lenlink(t_room *room, t_grp *grp)
{
	t_link	*link;
	int		len;

	link = room->link;
	len = 0;
	while (link)
	{
		if (link->room != grp->start)
		len++;
		link = link->next;
	}
	return (len);
}

t_link	*can_set_depth(t_room *room)
{
	t_link	*link;

	link = room->link;
	while (link)
	{
		if ((link->room->depth != 0 && link->room->depth > room->depth))
			return (link);
		link = link->next;
	}
	return (link);
}

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

int 	set_wave(t_room *room, int depth, t_grp *grp)
{
	t_link *link;

	if (set_depth(room, grp) || depth <= room->depth)
		return (0);

	while (link)
	{
		set_wave(link->room, depth, grp);
		link = link->next;
	}
}

/*
** moon causes waves
*/

void	moon(t_grp *grp)
{
	int depth;

	depth = 0;
	while (grp->end->depth == 0)
	{
		set_wave(grp->start, depth, grp);
		depth++;
	}
}

void 	finding_ways(t_grp *grp)
{
	t_room *room;


	room = grp->start;
	room->depth = 0;
	moon(grp);
	print_rooms_with_depth(grp->room);
}



/*_Bool set_wave(t_room *room, int prev_depth, t_grp *grp, _Bool force_go)
{
	t_link	*link;
	int		flag;
	int		len;

	link = room->link;
	prev_depth++;
	len = give_lenlink(room, grp);
	if ((flag = can_set_depth(room, len, grp)) == -1)
		return (0);
	while (link)
	{
		printf("\t\t%s %s\n", room->name, link->room->name);
		printf("--------------\n");
		print_rooms_with_depth(grp->room);

		if (link->room == grp->start)
			;
		else if (flag >= len && set_wave(link->room, prev_depth, grp, 0))
			return (1);
		else if (link->room->depth == 0 || link->room->depth > prev_depth)
		{
			link->room->depth = prev_depth;
			if (grp->end == link->room)
				return (1);
		}
		else if (link->room->depth <= prev_depth)
			flag++;
		link = link->next;
		if (!link && len == flag && flag++)
			link = room->link;
	}
	printf("==============\n");
	printf("\t\t%s\n", room->name);
	print_rooms_with_depth(grp->room);
	printf("==============\n");
	return (0);
}*/