/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_room_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 23:38:44 by ylila             #+#    #+#             */
/*   Updated: 2020/02/14 23:41:31 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizual.h"

static void	get_distinct_coords(t_room *room, int *dist_x, int *dist_y)
{
	t_room	*head;
	t_room	*curr;
	int		count_x;
	int		count_y;

	head = room;
	while (room)
	{
		count_x = 0;
		count_y = 0;
		curr = head;
		while (curr != room)
		{
			if (curr->x == room->x)
				++count_x;
			if (curr->y == room->y)
				++count_y;
			curr = curr->next;
		}
		if (count_x == 0)
			++*dist_x;
		if (count_y == 0)
			++*dist_y;
		room = room->next;
	}
}

Sint16		get_diam(int win_w, int win_h, t_room *room)
{
	int		diam_x;
	int		diam_y;
	int		dist_x;
	int		dist_y;

	dist_x = 0;
	dist_y = 0;
	get_distinct_coords(room, &dist_x, &dist_y);
	diam_x = win_w / (dist_x * 10);
	diam_y = win_h / (dist_y * 10);
	return (diam_x < diam_y ? (Sint16)diam_x : (Sint16)diam_y);
}

void		get_scale_offset(t_viz *vz, t_room *room)
{
	Sint16	x_min;
	Sint16	x_max;
	Sint16	y_min;
	Sint16	y_max;

	x_min = SDL_MAX_SINT16;
	y_min = SDL_MAX_SINT16;
	x_max = SDL_MIN_SINT16;
	y_max = SDL_MIN_SINT16;
	while (room)
	{
		x_min = ((Sint16)room->x < x_min) ? room->x : x_min;
		x_max = ((Sint16)room->x > x_max) ? room->x : x_max;
		y_min = ((Sint16)room->y < y_min) ? room->y : y_min;
		y_max = ((Sint16)room->y > y_max) ? room->y : y_max;
		room = room->next;
	}
	vz->scale_x = vz->win_w / (double)(y_max - y_min);
	vz->scale_y = vz->win_h / (double)(x_max - x_min);
	vz->offset_x = x_min;
	vz->offset_y = y_min;
}

void		get_center(t_viz *vz, t_room *curr_room)
{
	Sint16	cent_x;
	Sint16	cent_y;

	cent_x = (Sint16)ft_floor(vz->win_w / 100. +
			(curr_room->x - vz->offset_x) * vz->scale_x);
	cent_y = (Sint16)ft_floor(vz->win_h / 100. +
			(curr_room->y - vz->offset_y) * vz->scale_y);
	if (cent_x >= vz->win_w)
		cent_x = vz->win_w - vz->diam / 2;
	if (cent_y >= vz->win_h)
		cent_y = vz->win_h - vz->diam / 2;
	curr_room->cent_x = cent_x;
	curr_room->cent_y = cent_y;
}
