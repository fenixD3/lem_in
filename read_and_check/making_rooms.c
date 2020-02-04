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

#include "../includes/lem_in.h"
#include "readfile.h"

void	making_links(t_fline *lst, t_room **room)
{
	t_room *tmp;
	t_room *prev;

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

t_room	*making_rooms_and_links(t_fline *lst, t_grp *grp)
{
	t_fline *head;
	t_room	*room;
	int		tmp;

	room = NULL;
	head = lst;
	while (!(tmp = type_of_line(head->line)) || tmp == 5)
		head = head->next;
	while (head)
	{
		if ((tmp = type_of_line(head->line)) == 1 || tmp == 2)
		{
			head = head->next;
			push_room(&room, head->line);
			if (tmp == 1)
				grp->start = room;
			else
				grp->end = room;
		}
		else if (tmp == 3)
			push_room(&room, head->line);
		head = head->next;
	}
	making_links(lst, &room);
	return (room);
}
