//
// Created by Mort Deanne on 23/01/2020.
//

#include <lem_in.h>
#include "ways_and_ants.h"

void	push_way(t_way **head, t_room *room)
{
	t_way *new;

	new = (t_way*)ml_malloc(sizeof(t_way));
	new->room = room;
	new->ants = 0;
	new->open = 0;
/*	new->next = NULL;
	if (*head)*/
	new->next = (*head);
	*head = new;
}

t_way *make_way_list(t_link *link, int max_way_num)
{
	t_room	*max_way;
	t_way	*head;
	t_link	*l_way;

	head = NULL;
	while (1)
	{
		l_way = link;
		max_way_num = 0;
		max_way = l_way->room;
		while (l_way)
		{
			if (max_way_num < l_way->room->way_nu &&
				(!head || head->room->way_nu > l_way->room->way_nu))
			{
				max_way_num = l_way->room->way_nu;
				max_way = l_way->room;
			}
			l_way = l_way->next;
		}
		if (!max_way_num || (head && head->room->way_nu <= max_way->way_nu))
			break ;
		//if (max_way->way_nu)
		push_way(&head, max_way);
	}
	return (head);
}

