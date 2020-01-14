//
// Created by Mort Deanne on 14/01/2020.
//

#include <libft.h>
#include <get_next_line.h>
#include "readfile.h"

void add_line_lst(t_fline **head, t_fline **tail, char *line)
{
	t_fline *new;

	if (!(new = (t_fline*)ml_malloc(sizeof(t_fline))))
		go_exit(1);
	new->next = NULL;
	if (!*head)
		*head = new;
	new->line = line;
	if (*tail)
		(*tail)->next = new;
	*tail = new;
}

t_fline *read_and_save_file(int fd)
{
	char	*line;
	t_fline	*tail;
	t_fline *head;

	tail = NULL;
	head = NULL;
	line = NULL;
	while(get_next_line(fd, &line) > 0)
	{
		if (!*line)
		{
			////check list on errors
			break ;
		}
		add_line_lst(&head, &tail, line);
	}
	return (head);
}