/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rooms_links.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:27:10 by mdeanne           #+#    #+#             */
/*   Updated: 2020/02/04 18:27:12 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	push_room(t_room **head, char *line)
{
	t_room	*new;
	char	*tmp;
	char	*new_line;

	new = (t_room*)ml_malloc(sizeof(t_room));
	new_line = ft_strdup(line);
	new->next = NULL;
	new->link = NULL;
	new->depth = 0;
	new->way_nu = 0;
	if (*head)
		new->next = *head;
	new->name = new_line;
	tmp = ft_strchr(new_line, ' ');
	new->x = ft_atoi(tmp);
	*tmp = '\0';
	tmp++;
	tmp = ft_strchr(tmp, ' ');
	new->y = ft_atoi(tmp);
	*head = new;
	check_rooms_duplicates(*head);
}

void	find_rooms(t_room **room1, t_room **room2, char *name)
{
	char *name2;
	char *tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(name) + 1))))
		go_exit("ERROR: Can't alloc memory");
	name = ft_strcpy(tmp, name);
	name2 = ft_strchr(name, '-') + 1;
	*(name2 - 1) = '\0';
	while (*name || *name2)
	{
		if (*name && *room1 && ft_strcmp(name, (*room1)->name) != 0)
			*room1 = (*room1)->next;
		else if (name)
			*name = '\0';
		if (*name2 && *room2 && ft_strcmp(name2, (*room2)->name) != 0)
			*room2 = (*room2)->next;
		else if (name2)
			*name2 = '\0';
	}
	if (!*room1 || !*room2)
		go_exit("ERROR: file has link to non-existent room");
	free(tmp);
}

void	add_links(t_room *head, char *line)
{
	t_link	*new1;
	t_link	*new2;
	t_room	*room1;
	t_room	*room2;

	room1 = head;
	room2 = head;
	find_rooms(&room1, &room2, line);
	new1 = (t_link*)ml_malloc(sizeof(t_link));
	new2 = (t_link*)ml_malloc(sizeof(t_link));
	new1->room = room2;
	new2->room = room1;
	new1->next = NULL;
	new2->next = NULL;
	if (room1->link)
		new1->next = room1->link;
	if (room2->link)
		new2->next = room2->link;
	room1->link = new1;
	room2->link = new2;
}

_Bool	check_ways(t_link *link)
{
	while (link)
	{
		if (link->room->way_nu)
			return (1);
		link = link->next;
	}
	return (0);
}
