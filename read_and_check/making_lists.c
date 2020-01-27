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
	t_fline *tmp;

	///////////
	int fd = 0;
	if ((fd = open("/Users/mdeanne/lem_in/test0", O_RDONLY)) < 0)
		go_exit(3);
	///////////

	fileline = read_and_save_file(fd);
	tmp = fileline;
	while (tmp)
	{
		printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
	printf("\n");
	grp->room = making_rooms_and_links(fileline, grp);
	return (ft_atoi(fileline->line));
}


