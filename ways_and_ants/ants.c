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

#include "ways_and_ants.h"
#include "vizual.h"

void	kill_ants(t_ant **head, t_room *end)
{
	t_ant *ant;
	t_ant *prev;

	while (*head && (*head)->room == end)
	{
		ant = *head;
		*head = (*head)->next;
		ml_free((void*)ant);
	}
	if (*head == NULL)
		return ;
	prev = *head;
	ant = prev->next;
	while (ant)
	{
		if (ant->room == end)
		{
			prev->next = ant->next;
			ml_free((void*)ant);
		}
		else
			prev = prev->next;
		ant = prev->next;
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

_Bool	put_ants_statuses(t_ant *ant, t_viz *vz, t_grp *grp, t_way *ways)
{
	if (!ant)
		return (0);
	vz->flg ? set_action(vz, 0) : 0;
	vz->flg ? SDL_RenderClear(vz->renderer) : 0;
	vz->flg ? SDL_SetRenderDrawColor(vz->renderer, 0, 0, 0, 0) : 0;
	vz->flg ? SDL_RenderClear(vz->renderer) : 0;
	while (ant)
	{
		ft_printf("L%d-%s", ant->number, ant->room->name);
		vz->flg ? draw(grp, vz, ant, ways) : 0;
		ant = ant->next;
		if (ant)
			ft_printf(" ");
	}
	vz->flg ? SDL_RenderPresent(vz->renderer) : 0;
	vz->flg ? SDL_Delay(1000) : 0;
	ft_printf("\n");
	return (1);
}

void	put_ants_steps(t_way *ways, t_grp *grp, t_viz *vz)
{
	t_ant	*head;
	int		i;

	head = NULL;
	if (ways->room == grp->end)
	{
		i = 1;
		while (ways->ants-- > 1)
			ft_printf("L%d-%s ", i++, grp->end->name);
		ft_printf("L%d-%s\n", i, grp->end->name);
		vz->flg ? set_action(vz, 1) : 0;
		vz->flg ? SDL_RenderClear(vz->renderer) : 0;
		vz->flg ? SDL_SetRenderDrawColor(vz->renderer, 0, 0, 0, 0) : 0;
		vz->flg ? SDL_RenderClear(vz->renderer) : 0;
		vz->flg ? draw(grp, vz, head, ways) : 0;
		vz->flg ? SDL_RenderPresent(vz->renderer) : 0;
		vz->flg ? SDL_Delay(1000) : 0;
		return ;
	}
	push_ants(&head, ways, grp);
	while (put_ants_statuses(head, vz, grp, ways))
		push_ants(&head, ways, grp);
}
