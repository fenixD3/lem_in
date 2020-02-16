/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:27:21 by mdeanne           #+#    #+#             */
/*   Updated: 2020/02/04 18:27:25 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ptintf.h"
#include "lem_in.h"
#include "readfile.h"

void	making_links(t_fline *lst, t_room **room)
{
	t_room *tmp;
	t_room *prev;

	tmp = NULL;
	while (lst)
	{
		if (type_of_line(lst->line) == 4)
			add_links(*room, lst->line);
		lst = lst->next;
	}
	while (!(*room)->link)
		*room = (*room)->next;
	prev = *room;
	if (prev->next)
		tmp = prev->next;
	while (tmp)
	{
		if (!tmp->link)
			prev->next = tmp->next;
		else
			prev = prev->next;
		tmp = tmp->next;
	}
}

int		type_of_line(char *line)
{
	if (line[0] == '#')
	{
		if (line[1] != '#')
			return (0);
		else if (!ft_strcmp(line + 1, "#start"))
			return (1);
		else if (!ft_strcmp(line + 1, "#end"))
			return (2);
		else
			return (0);
	}
	else if (ft_strchr(line, ' '))
		return (3);
	else if (ft_strchr(line, '-'))
		return (4);
	else if (ft_isdigit(line[0]))
		return (5);
	return (-1);
}

void	check_start_end(int tmp, t_grp *grp, t_room *room)
{
	if (tmp == 1 && grp->start == NULL)
	{
		if (grp->start != NULL)
			go_exit("ERROR: ##start duplicated");
		grp->start = room;
	}
	else
	{
		if (grp->end != NULL)
			go_exit("ERROR: ##end duplicated");
		grp->end = room;
	}
}

void	skip_comment(t_fline **head, int type)
{
	t_fline *next;
	int		type_next;

	next = (*head)->next;
	type_next = type_of_line(next->line);
	if (type_next == 0)
		while (next && (type_next = type_of_line(next->line)) == 0)
			next = next->next;
	if (!next || type_next != 3)
	{
		ft_printf("ERROR: after ##%s where is not room\n",
				(type == 1) ? "start" : "end");
		exit(1);
	}
	*head = next;
}

t_room	*making_rooms_and_links(t_fline *lst, t_grp *grp)
{
	t_fline *head;
	t_room	*room;
	int		type;

	room = NULL;
	head = lst;
	while (!(type = type_of_line(head->line)) || type == 5)
		head = head->next;
	while (head)
	{
		if (((type = type_of_line(head->line)) == 1 || type == 2))
		{
			skip_comment(&head, type);
			push_room(&room, head->line);
			check_start_end(type, grp, room);
		}
		else if (type == 3)
			push_room(&room, head->line);
		head = head->next;
	}
	making_links(lst, &room);
	return (room);
}
