//
// Created by Yeste Lila on 05/02/2020.
//

#include "vizual.h"

void init_viz(t_viz *viz, t_room *room)
{
	SDL_DisplayMode	dm;

	if (SDL_Init(SDL_INIT_EVERYTHING))
		viz_error(viz);
	if (SDL_GetCurrentDisplayMode(0, &dm))
		viz_error(viz);
	viz->win_w = dm.w / 2;
	viz->win_h = dm.h / 2;
	if (!(viz->window = SDL_CreateWindow("a", 40, 40, viz->win_w, viz->win_h,
			SDL_WINDOW_SHOWN)))
		viz_error(viz);
	if (!(viz->renderer = SDL_CreateRenderer(viz->window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		viz_error(viz);
	viz->diam = get_diam(viz->win_w, viz->win_h, room);
	get_offset(viz, room);
}

void	drawing_all(t_grp grp, t_viz vz)
{
	draw_field(grp, vz);
}

void	draw_field(t_grp grp, t_viz vz)
{
	t_room	*room;
	t_room	*prev;

	room = grp.room;
	prev = NULL;
	//SDL_RenderClear(vz.renderer);
	SDL_SetRenderDrawColor(vz.renderer, 0, 0, 0, 0);
	SDL_RenderClear(vz.renderer);
	while (room)
	{
		handle_events();
		get_center(&vz, room, prev);
		if (room == grp.start)
			aacircleRGBA(vz.renderer, vz.cent_x,//room->x + vz.offset_x,
				vz.cent_y,//room->y + vz.offset_y,
				vz.diam / 2, 0, 0xFF, 0, 0xFF);
		else if (room == grp.end)
			aacircleRGBA(vz.renderer, vz.cent_x,//room->x + vz.offset_x,
				vz.cent_y,//room->y + vz.offset_y,
				vz.diam / 2, 0, 0, 0xFF, 0xFF);
		else
			aacircleRGBA(vz.renderer, vz.cent_x,//room->x + vz.offset_x,
				vz.cent_y,//room->y + vz.offset_y,
				vz.diam / 2, 0xFF, 0, 0, 0xFF);
		//stringRGBA(vz.renderer, vz.cent_x, vz.cent_y, room->name, 0xFF, 0, 0, 0xFF);
		prev = room;
		room = room->next;
	}
	SDL_RenderPresent(vz.renderer);
	SDL_Delay(5000);
}

void	make_vizual(t_viz *vz, t_grp grp)
{
	init_viz(vz, grp.room);
	drawing_all(grp, *vz);
}

/*int 	main(int ac, char **av)
{
	t_viz	vz;
	_Bool	run = 1;

	init_viz(&vz, NULL);
	while (run)
	{
		handle_events(&vz, &run);
		SDL_RenderClear(vz.renderer);
		SDL_SetRenderDrawColor(vz.renderer, 0, 0, 0, 0);
		SDL_RenderClear(vz.renderer);
		//SDL_SetRenderDrawColor(vz.renderer, 0xFF, 0, 0, 0xFF);
		//SDL_RenderDrawLine(vz.renderer, 40, 40, 200, 200);
		aalineRGBA(vz.renderer, 40, 40, 100, 100, 0xFF, 0, 0, 0xFF);
		aacircleRGBA(vz.renderer, vz.win_w / 2, vz.win_h / 2, 100, 0, 0xFF, 0, 0xFF);
		SDL_RenderPresent(vz.renderer);
	}
	quit_viz(&vz);
}*/
