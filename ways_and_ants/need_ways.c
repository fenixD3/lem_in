/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:28:27 by mdeanne           #+#    #+#             */
/*   Updated: 2020/02/04 18:28:29 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		which_ways(t_grp *grp, int *max)
{
	int		start_ways;
	int		end_ways;
	t_link	*link;

	start_ways = 0;
	end_ways = 0;
	link = grp->start->link;
	while (link)
	{
		if (!link->room->way_nu)
			start_ways++;
		link = link->next;
	}
	link = grp->end->link;
	while (link)
	{
		if (!link->room->way_nu)
			end_ways++;
		link = link->next;
	}
	return (start_ways > end_ways ? start_ways : end_ways);
}

int		need_ways(t_grp *grp)
{
	return (0);
}
