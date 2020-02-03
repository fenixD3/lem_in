//
// Created by Mort Deanne on 14/01/2020.
//

#include <stdlib.h>
#include "includes/lem_in.h"
#include <ways_and_ants.h>
////
#include <time.h>
#include <stdio.h>
void put_ants_steps(t_way *ways, t_grp *grp); /// Плохо подключалось
////


int main(int ac, char **av)
{
	t_grp grp;
	t_way *ways;
	t_fline *flist;
	int 	ants;

	grp.room = NULL;
	grp.start = NULL;
	grp.end = NULL;


	flist = making_lists(&grp, &ants);

	if (!is_one_step_way(&grp))
		finding_ways(&grp);

	if (!check_ways(grp.start->link)) /// это нужно протестировать но уменя нет карт
		go_exit("ERROR: there is no way from start to end");
	ways = count_ants_for_way(grp.start->link, &grp, ants);
	while (flist)
	{
		ft_putendl(flist->line);
		flist = flist->next;
	}
	ft_putchar('\n');
	put_ants_steps(ways, &grp);
	exit(0);
}