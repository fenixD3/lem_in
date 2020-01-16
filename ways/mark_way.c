//
// Created by Mort Deanne on 16/01/2020.
//



#include "../includes/lem_in.h"

int		set_and_go_back(t_room *room, t_grp *grp)
{
	static int	way_num;
	t_link		*link;

	link = room->link;
	while (link)
	{
		if (link->room->way_number == 0 && room->depth - link->room->depth == 1)
			break ;
		link = link->next;
	}
	if (!link)
		return (0);
	if (link->room != grp->start)
		link->room->way_number = way_num;
	else
		return(grp->start->depth);
	return(set_and_go_back(link->room, grp));
}