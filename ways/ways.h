//
// Created by Mort Deanne on 23/01/2020.
//

#ifndef WAYS_H
#define WAYS_H

#include <lem_in.h>

typedef		struct s_way
{
	t_room			*way;
	int			 	ants;
	_Bool			open;
	struct s_way	*next;
}			t_way;



#endif
