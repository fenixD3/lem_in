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

void	print_rooms_with_depth(t_room *start, t_room *room, t_link *link, int depth)
{
	printf(".............\nroom = %s  link = %s  depth = %d\n-------------\n",room->name, link->room->name, depth);
	while (start)
	{
		printf("%s : %d\n", start->name, start->depth);
		start = start->next;
	}
	printf("--------------\n");
}

void	print_way(t_room *room, t_grp *grp)
{
	t_link *link;

	link = room->link;
	printf("Way: %d\n%s <- ", room->way_number,grp->start->name);
	while (link->room != grp->start)
	{
		printf("%s <- ", room->name);
		while (link && !link->room->way_number)
			link = link->next;
		if (!link)
		{
			printf("ALARM\n");
			return ;
		}
		room = link->room;
		link = room->link;
	}
}

void	print_ways(t_grp *grp)
{
	t_room *end;
	t_link *link;

	end = grp->end;
	link = end->link;
	while (link)
	{

		if (link->room->way_number)
		{
			printf("------------\n");
			print_way(link->room, grp);
			printf("------------\n");
		}
		link = link->next;
	}
}

void	print_seted_way_number(t_room *room)
{
	t_link *link;
	link = room->link;
	while (link)
	{
		if (link->room->way_number)
			printf("%d ", link->room->way_number);
		else
			printf("-");
		link = link->next;
	}
	printf("\n");
}