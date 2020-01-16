//
// Created by Mort Deanne on 14/01/2020.
//

#include <stdlib.h>
#include "includes/lem_in.h"

////
#include <time.h>
#include <stdio.h>
////

int main(void)
{
	t_grp grp;

	grp.room = NULL;
	grp.start = NULL;
	grp.end = NULL;

	/////
	clock_t start, maked_list, end;
	start = clock();
	/////

	making_lists(&grp);
	maked_list = clock();;
	finding_ways(&grp);
	end = clock();

	double seconds1 = ((double)(maked_list - start))/CLOCKS_PER_SEC;
	double seconds2 = ((double)(end - maked_list))/CLOCKS_PER_SEC;
	double seconds3 = ((double)(end - start))/CLOCKS_PER_SEC;

	printf("maked list:\t%f\nfind way:\t%f\nall:\t\t%f\npercent:\t%.2f%%\n", seconds1, seconds2, seconds3, (seconds2/seconds3)*100);


	exit(0);
}