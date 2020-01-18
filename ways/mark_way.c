//
// Created by Mort Deanne on 16/01/2020.
//



#include "../includes/lem_in.h"

int		set_and_go_back(t_room *room, t_grp *grp)
{
	static int	way_num;
	t_link		*link;

	if (room == grp->end)
		way_num++;
	link = room->link;

	int i = 0;
	while (1)
	{
		if (link->room->way_number == 0 && room->depth - link->room->depth == 1)
		{
			if (link->room != grp->start)
				link->room->way_number = way_num;
			else
				return(way_num);
			if (set_and_go_back(link->room, grp))
				return(way_num);
		}
		link = link->next;
		i++;
		if (!link)
		{
			room->way_number = 0;
			return (0);
		}
	}
}