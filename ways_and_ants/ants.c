/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:28:01 by mdeanne           #+#    #+#             */
/*   Updated: 2020/02/04 18:28:03 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ways_and_ants.h>
#include <stdio.h> ////!!!!!!!!!!!!!!!!!!!!

t_room	*find_next_room(t_ant *ant, t_grp *grp)
{
	t_link *link;

	link = ant->room->link;
	while (link)
	{
		if (link->room->way_nu == ant->room->way_nu &&
											link->room != ant->prev_room)
			break ;
		link = link->next;
	}
	return (link ? link->room : grp->end);
}

void	kill_ants(t_ant **head, t_room *end)
{
	t_ant *tmp;

	while (*head && (*head)->room == end)
	{
		tmp = *head;
		*head = (*head)->next;
		ml_free((void*)tmp);
	}
}

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

void	push_ants(t_ant **head, t_way *ways, t_grp *grp)
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

void	put_ants_steps(t_way *ways, t_grp *grp)
{
	t_ant	*head;
	int		i;

	if (ways->room == grp->end)
	{
		i = 1;
		while (ways->ants-- > 1)
			printf("L%d-%s ", i++, grp->end->name);
		printf("L%d-%s", i, grp->end->name);
		return ;
	}
	head = NULL;
	push_ants(&head, ways, grp);
	while (put_ants_statuses(head))
		push_ants(&head, ways, grp);
}
