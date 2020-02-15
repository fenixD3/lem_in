/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 21:02:52 by mdeanne           #+#    #+#             */
/*   Updated: 2020/02/15 21:03:38 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_ptintf.h"

void	check_rooms_duplicates(t_room *head)
{
	t_room *room;

	room = head->next;
	while (room)
	{
		if (!strcmp(head->name, room->name))
		{
			ft_printf("ERROR: room \"%s\" name is duplicate\n", head->name);
			exit(1);
		}
		if (head->x == room->x && head->y == room->y)
		{
			ft_printf(
			"ERROR: room \"%s\" and room \"%s\" coordinates is duplicate\n",
			head->name, room->name);
			exit(1);
		}
		room = room->next;
	}
}
