/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:28:14 by mdeanne           #+#    #+#             */
/*   Updated: 2020/02/04 18:28:16 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		set_depth(t_room *room, t_grp *grp)
{
	t_link	*link;
	int		setted;

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

int		wave(t_room *room, t_room *prev, int depth, t_grp *grp)
{
	t_link		*link;
	static int	setted;
	int			tmp;

	if (room->depth == 0)
		setted = 0;
	if (!(tmp = set_depth(room, grp)) && depth == room->depth)
		return (0);
	setted += tmp;
	link = room->link;
	while (link)
	{
		if (link->room != prev && depth >= link->room->depth &&
				link->room->depth > room->depth && link->room->way_nu == 0)
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

int		is_one_step_way(t_grp *grp)
{
	t_link *link;

	link = grp->start->link;
	while (link)
	{
		if (link->room == grp->end)
			return (1);
		link = link->next;
	}
	return (0);
}

void	finding_ways(t_grp *grp)
{
	t_room *room;

	room = grp->start;
	room->depth = 0;
	while (moon(grp))
		marking_list(grp);
	set_start_depth(grp);
}
