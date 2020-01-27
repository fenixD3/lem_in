//
// Created by Mort Deanne on 14/01/2020.
//

#include "../includes/lem_in.h"
#include "readfile.h"

void push_room(t_room **head, char *line)
{
	t_room	*new;
	char 	*tmp;
	char 	*new_line;

	new = (t_room*)ml_malloc(sizeof(t_room));
	new_line = ft_strdup(line);
	new->next = NULL;
	new->link = NULL;
	new->depth = 0;
	new->way_nu = 0;
	if (*head)
		new->next = *head;
	new->name = new_line;
	tmp =  ft_strchr(new_line, ' ');
	new->x = ft_atoi(tmp);
	*tmp = '\0';
	tmp++;
	tmp =  ft_strchr(tmp, ' ');
	new->y = ft_atoi(tmp);
	*head = new;
}

void	find_rooms(t_room **room1, t_room **room2, char *name)
{
	char *name2;

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
	if (!room1 || !room2)
		go_exit(1);
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

int		which_type_of_line(char *line)
{
	if (line[0] == '#')
	{
		if (line[1] != '#')
			return (0);
		else if (!ft_strcmp(line + 1, "#start"))
			return (1);
		else if (!ft_strcmp(line + 1, "#end"))
			return (2);
	}
	else if (ft_strchr(line, ' ') && check_room(line)) // check_room
		return (3);
	else if (ft_strchr(line, '-')) // check_link
		return (4);
	return (-1);
}

void	making_links(t_fline *lst, t_room **room)
{
	t_room *tmp;
	t_room *prev;

	while (lst)
	{
		if (which_type_of_line(lst->line) == 4)
			add_links(*room, lst->line);
		lst = lst->next;
	}
	while (!(*room)->link)
		*room = (*room)->next;
	prev = *room;
	if (prev->next)
		tmp = prev->next; ///  нужно проверить если линки между вершинами (в черкере или здесь)
	while (tmp)
	{
		if (!tmp->link)
			prev->next = tmp->next;
		else
			prev = prev->next;
		tmp = tmp->next;
	}
}

t_room *making_rooms_and_links(t_fline *lst, t_grp *grp)
{
	t_fline *head;
	t_room	*room;
	int		tmp;

	room = NULL;

	head = lst->next;
	while (head)
	{
		if ((tmp = which_type_of_line(head->line)) == 1 || tmp == 2)
		{
			head = head->next;
			check_room(head->line);
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