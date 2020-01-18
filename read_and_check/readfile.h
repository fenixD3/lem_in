//
// Created by Mort Deanne on 14/01/2020.
//

#ifndef READFILE_H
#define READFILE_H

typedef struct	s_fline
{
	char			*line;
	struct s_fline	*next;
}				t_fline;

t_fline *read_and_save_file(int fd);

#endif
