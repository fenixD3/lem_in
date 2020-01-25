//
// Created by Mort Deanne on 11/01/2020.
//

#include "readfile.h"
#include "libft.h"
#include "lem_in.h"


#include <fcntl.h>
#include <stdio.h>

int		making_lists(t_grp *grp)
{
	t_fline	*fileline;

	///////////
	int fd;
	if ((fd = open("/Users/mdeanne/lem_in/Maps/test_sub", O_RDONLY)) < 0)
		go_exit(3);


	///////////

	fileline = read_and_save_file(fd);
	grp->room = making_rooms_and_links(fileline, grp);
	return (ft_atoi(fileline->line));
}


