//
// Created by Mort Deanne on 25/01/2020.
//


#include <ways_and_ants.h>

void	print_ants(t_ant *ant);


t_room *find_next_room(t_ant *ant, t_grp *grp)
{
	t_link *link;

	link = ant->room->link;
	while (link)
	{
		if (link->room->way_nu == ant->room->way_nu && link->room != ant->prev_room)
			break ;
		link = link->next;
	}
	return (link ? link->room : grp->end);
}

/*void	kill_ant(t_ant **head, t_room *end)
{
	t_ant	*pretail;
	t_ant	*tail;

	if ((*head)->room == end)
	{
		while (*head)
		{
			pretail = *head;
			*head = (*head)->next;
			ml_free((void*)pretail);
		}
		return ;
	}
	pretail = *head;
	while (pretail->next && pretail->next->room != end)
		pretail = pretail->next;
	if (!(tail = pretail->next))
		return ;
	pretail->next = NULL;
	pretail = tail;
	while (tail)
	{
		ml_free((void*)pretail);
		pretail = tail;
		tail = tail->next;
	}
}*/

void	kill_ants(t_ant **head, t_room *end)
{
	t_ant *tmp;

	static int i;
	i++;
	if (i == 3)
		i = i;
	while (*head && (*head)->room == end)
	{
		tmp = *head;
		*head = (*head)->next;
		ml_free((void*)tmp);
	}
}

/*void push_ants(t_ant **head, t_way *ways, t_grp *grp)
{
	t_ant	*ant;
	t_room	*prev_room;

	if (*head)
		kill_ants(head, grp->end);
	ant = *head;
	while (ant)
	{
		prev_room = ant->room;
		ant->room = find_next_room(ant, grp);
		ant->prev_room = prev_room;
		ant = ant->next;
	}
	while (ways && ways->ants && (ways->ants)--)
	{
		ant = (t_ant*)ml_malloc(sizeof(t_ant));
		ant->prev_room = grp->start;
		ant->room = ways->room;
		ant->number = (*head) ? (*head)->number + 1 : 1;
		ant->next = *head;
		*head = ant;
		ways = ways->next;
	}
}*/

void	create_ant(t_ant **head, t_ant **tail, t_way *ways, t_room *start)
{
	t_ant *ant;

	ant = (t_ant*)ml_malloc(sizeof(t_ant));
	ant->prev_room = start;
	ant->room = ways->room;
	ant->next = NULL;
	ant->number = 1;
	if (*tail)
	{
		ant->number += (*tail)->number;
		(*tail)->next = ant;
	}
	else
		*head = ant;
	*tail = ant;
}

void push_ants(t_ant **head, t_way *ways, t_grp *grp)
{
	t_ant	*ant;
	t_room	*prev_room;
	t_ant	*tail;

	if (*head)
		kill_ants(head, grp->end);
	ant = *head;
	tail = ant;
	while (ant)
	{
		prev_room = ant->room;
		ant->room = find_next_room(ant, grp);
		ant->prev_room = prev_room;
		tail = ant;
		ant = ant->next;
	}
	while (ways && ways->ants && (ways->ants)--)
	{
		create_ant(head, &tail, ways, grp->start);
		ways = ways->next;
	}
}

#include <stdio.h>

_Bool	put_ants_statuses(t_ant *ant)
{
	if (!ant)
		return (0);
	while (ant)
	{
		printf("L%d-%s", ant->number, ant->room->name);
		ant = ant->next;
		if (ant)
			printf(" ");
	}
	printf("\n");
	return (1);
}

void put_ants_steps(t_way *ways, t_grp *grp)
{
	t_ant *head;

	head = NULL;
	push_ants(&head, ways, grp);
	while (put_ants_statuses(head))
		push_ants(&head, ways, grp);
}