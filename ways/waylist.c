//
// Created by Mort Deanne on 23/01/2020.
//

#include <lem_in.h>
#include "ways.h"


void	push_way(t_way **head, t_room *room)
{
	t_way *new;

	new = (t_way*)ml_malloc(sizeof(t_way));
	new->way = room;
	new->ants = 0;
	new->open = 0;
	new->next = NULL;
	if (!*head)
		*head = new;
	else
		(*head)->next = new;
}

t_room	*find_max_way(t_link *l_way)
{
	int		max_way_num;
	t_room	*max_way;

	max_way_num = 0;
	while (l_way)
	{
		if (l_way->room->way_number > max_way_num)
		{
			max_way_num = l_way->room->way_number;
			max_way = l_way->room;
		}
		l_way = l_way->next;
	}
	return (0);
}

t_room	*find_max_not_added_way(t_link *l_way, int added_way_number)
{
	int		max_way_num;
	t_room	*max_way;

	if (!added_way_number)
		return (find_max_way(l_way));

	max_way_num = 0;
	while (l_way)
	{
		if (l_way->room->way_number > max_way_num && l_way->room->way_number )
		{

		}
		l_way = l_way->next;
	}
}