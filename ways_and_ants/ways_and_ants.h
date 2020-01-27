//
// Created by Mort Deanne on 23/01/2020.
//

#ifndef WAYS_H
#define WAYS_H

#include <lem_in.h>

typedef struct	s_way
{
	t_room			*room;
	int			 	ants;
	_Bool			open;
	struct s_way	*next;
}				t_way;

typedef struct	s_ant
{
	t_room			*room;
	t_room			*prev_room;
	int 			number;
	struct s_ant	*next;
}				t_ant;

void			push_way(t_way **head, t_room *room);
t_way			*make_way_list(t_link *link, int max_way_num);
t_way			*count_ants_for_way(t_link *link, t_grp *grp, int ants);

#endif
