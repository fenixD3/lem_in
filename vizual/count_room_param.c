//
// Created by da.filiptsev on 07.02.2020.
//

#include "vizual.h"

Sint16	get_diam(int win_w, int win_h, t_room *room)
{
	int	diam;

	diam = win_w * win_h / rooms_count(room);
	if (diam > SDL_MAX_SINT16)
		diam = SDL_MAX_SINT16 - 10000;
	return ((Sint16)diam);
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
	vz->offset_x = ((Sint16)vz->win_w - (x_max - x_min) + RAD) / 2;
	vz->offset_y = ((Sint16)vz->win_h - (y_max - y_min) + RAD) / 2;
}
