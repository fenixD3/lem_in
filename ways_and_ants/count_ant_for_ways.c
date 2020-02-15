/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_ant_for_ways.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:28:08 by mdeanne           #+#    #+#             */
/*   Updated: 2020/02/14 23:36:31 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ways_and_ants.h"

static void		add_ant_in_way(t_way *way, int *ants)
{
	way->ants++;
	(*ants)--;
}

static _Bool	if_can_open_next_way_and_add_ant(t_way **way, int *ants)
{
	if (!*ants || !(*way)->next ||
			(*way)->room->depth + (*way)->ants - 1 != (*way)->next->room->depth)
		return (0);
	*way = (*way)->next;
	(*way)->open = 1;
	add_ant_in_way(*way, ants);
	return (0);
}

t_way			*count_ants_for_way(t_link *link, t_grp *grp, int ants)
{
	t_way *ways;
	t_way *tmp;

	ways = NULL;
	if (is_one_step_way(grp))
	{
		push_way(&ways, grp->end);
		ways->open = 1;
		ways->ants = ants;
		return (ways);
	}
	ways = make_way_list(link, 0);
	ways->open = 1;
	while (ants)
	{
		tmp = ways;
		while (ants && tmp && (tmp->open))
		{
			add_ant_in_way(tmp, &ants);
			if_can_open_next_way_and_add_ant(&tmp, &ants);
			tmp = tmp->next;
		}
	}
	return (ways);
}

t_room			*find_next_room(t_ant *ant, t_grp *grp)
{
	t_link *link;

	link = ant->room->link;
	while (link)
	{
		if (link->room->way_nu == ant->room->way_nu &&
			link->room != ant->prev_room)
			break ;
		link = link->next;
	}
	return (link ? link->room : grp->end);
}
