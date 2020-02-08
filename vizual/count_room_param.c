//
// Created by da.filiptsev on 07.02.2020.
//

#include "vizual.h"

Sint16	get_diam(int win_w, int win_h, t_room *room)
{
	int		diam_x;
	int		diam_y;
	t_room	*head;
	t_room	*curr;
	int 	dist_x;
	int 	dist_y;
	int 	count_x;
	int		count_y;

	//diam_x = ft_sqrt(win_w * win_h / rooms_count(room), 0) / 2;
	head = room;
	dist_x = 0;
	dist_y = 0;
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
			++dist_x;
		if (count_y == 0)
			++dist_y;
		room = room->next;
	}
	diam_x = win_w / (dist_x * 10);
	diam_y = win_h / (dist_y * 10);
	/*if (diam_x > SDL_MAX_SINT16)
		diam_x = SDL_MAX_SINT16 - 10000;*/
	return (diam_x < diam_y ? (Sint16)diam_x : (Sint16)diam_y);
}

int		rooms_count(t_room *room)
{
	int	cnt;

	cnt = 0;
	while (room)
	{
		++cnt;
		room = room->next;
	}
	return (cnt);
}

void	get_offset(t_viz *vz, t_room *room)
{
	Sint16	x_min;
	Sint16	x_max;
	Sint16	y_min;
	Sint16	y_max;
	Sint16	delta_x;
	Sint16	delta_y;

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
	delta_x = x_max - x_min;
	delta_y = y_max - y_min;
	vz->scale_x = vz->win_w / (double)delta_x;
	vz->scale_y = vz->win_h / (double)delta_y;
	vz->offset_x = x_min;
	vz->offset_y = y_min;
	/*vz->offset_x = ((Sint16)vz->win_w - (x_max - x_min) + vz->diam / 2) / 2;
	vz->offset_y = ((Sint16)vz->win_h - (y_max - y_min) + vz->diam / 2) / 2;*/
}

void	get_center(t_viz *vz, t_room *curr_room, t_room *prev_room)
{
	Sint16	cent_x;
	Sint16	cent_y;

	/*cent_x = curr_room->x + vz->offset_x;
	cent_y = curr_room->y + vz->offset_y;
	if (prev_room && cent_x <= prev_room->x + vz->offset_x)
		cent_x += vz->diam + 40;
	if (prev_room && cent_y <= prev_room->y + vz->offset_y)
		cent_y += vz->diam + 40;*/
	cent_x = (Sint16)floor(vz->win_w / 10. + (curr_room->x - vz->offset_x) * vz->scale_x);
	cent_y = (Sint16)floor(vz->win_h / 10. + (curr_room->y - vz->offset_y) * vz->scale_y);
	vz->cent_x = cent_x;
	vz->cent_y = cent_y;
}
