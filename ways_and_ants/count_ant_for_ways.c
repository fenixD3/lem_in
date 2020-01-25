//
// Created by Mort Deanne on 25/01/2020.
//

#include "ways_and_ants.h"

void print_ants_ways(t_way *way, int ants, int clear);

static void add_ant_in_way(t_way *way, int *ants)
{
	way->ants++;
	(*ants)--;
}

static _Bool	can_open_way(t_way *way)
{
	if (way->ants == way->next->room->depth)
		return (1);
	return (0);
}

static _Bool	if_can_open_next_way_and_add_ant(t_way **way, int *ants)
{
	if (!*ants || !(*way)->next || (*way)->room->depth + (*way)->ants - 1 != (*way)->next->room->depth)
		return (0);
	*way = (*way)->next;
	(*way)->open = 1;
	add_ant_in_way(*way, ants);
	return (0);
}

t_way *count_ants_for_way(t_link *link, int ants)
{
	t_way *ways;
	t_way *tmp;

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