/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:27:33 by mdeanne           #+#    #+#             */
/*   Updated: 2020/02/04 18:27:36 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>
#include <lem_in.h>
#include "readfile.h"

void		add_line_lst(t_fline **head, t_fline **tail, char *line)
{
	t_fline *new;

	if (!(new = (t_fline*)ml_malloc(sizeof(t_fline))))
		go_exit("ERROR: can't alloc memory");
	new->next = NULL;
	if (!*head)
		*head = new;
	new->line = line;
	if (*tail)
		(*tail)->next = new;
	*tail = new;
}

t_fline		*read_and_save_file(int fd)
{
	char	*line;
	t_fline	*tail;
	t_fline *head;
	int		flag;

	tail = NULL;
	head = NULL;
	line = NULL;
	flag = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!*line)
		{
			if (flag == 3)
				break ;
			if (get_next_line(fd, &line) > 0)
				go_exit("ERROR: file contains newline break");
		}
		flag = check_valid_line(line);
		add_line_lst(&head, &tail, line);
	}
	if (flag != 3)
		go_exit("ERROR: not complete file");
	return (head);
}
