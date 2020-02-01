//
// Created by Mort Deanne on 11/01/2020.
//

#include "readfile.h"
#include "libft.h"
#include "lem_in.h"


#include <fcntl.h>
#include <stdio.h>

t_fline		*making_lists(t_grp *grp, int *ants)
{
	t_fline	*fileline;
	t_fline *tmp;

	///////////
	int fd = 0;
	if ((fd = open("/Users/mdeanne/lem_in/test0", O_RDONLY)) < 0)
		go_exit("ERROR: in read_and_check file");
	///////////

	fileline = read_and_save_file(fd);

	grp->room = making_rooms_and_links(fileline, grp);
	if (!grp->start && !grp->end)
		go_exit("ERROR: file doesn't contain ##start and ##end nodes");
	if (!grp->start)
		go_exit("ERROR: file doesn't contain ##start node");
	if (!grp->end)
		go_exit("ERROR: file doesn't contain ##end node");
	tmp = fileline;
	while (tmp->line[0] == '#')
		tmp = tmp->next;
	*ants = ft_atoi(tmp->line);
	return (fileline);
}


