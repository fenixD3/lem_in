/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:28:22 by mdeanne           #+#    #+#             */
/*   Updated: 2020/02/04 18:28:23 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		set_and_go_back(t_room *room, t_grp *grp)
{
	static int	way_num;
	t_link		*link;

	if (room == grp->end)
		way_num++;
	link = room->link;
	while (1)
	{
		if (link->room->way_nu == 0 && room->depth - link->room->depth == 1)
		{
			if (link->room != grp->start)
				link->room->way_nu = way_num;
			else
				return (way_num);
			if (set_and_go_back(link->room, grp))
				return (way_num);
		}
		link = link->next;
		if (!link)
		{
			room->way_nu = 0;
			return (0);
		}
	}
}

void	clear_nonwayed_nodes_depth(t_room *room)
{
	while (room)
	{
		if (!room->way_nu)
			room->depth = 0;
		room = room->next;
	}
}

void	marking_list(t_grp *grp)
{
	while (set_and_go_back(grp->end, grp))
		;
	clear_nonwayed_nodes_depth(grp->room);
}

void	set_start_depth(t_grp *grp)
{
	t_link *l_start;
	t_link *l_end;

	l_start = grp->start->link;
	while (l_start)
	{
		while (l_start && !l_start->room->way_nu)
			l_start = l_start->next;
		if (!l_start)
			return ;
		l_end = grp->end->link;
		while (l_end->room->way_nu != l_start->room->way_nu)
			l_end = l_end->next;
		l_start->room->depth = l_end->room->depth + 1;
		l_start = l_start->next;
	}
}
