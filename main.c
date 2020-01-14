//
// Created by Mort Deanne on 14/01/2020.
//

#include <stdlib.h>
#include "includes/lem_in.h"



int main(void)
{
	t_grp *grp;

	grp->room = NULL;
	grp->start = NULL;
	grp->end = NULL;

	making_lists(&grp);
	finding_ways(&grp);


	exit(0);
}