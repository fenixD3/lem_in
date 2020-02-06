//
// Created by Yeste Lila on 05/02/2020.
//

#include "vizual.h"
#include "lem_in.h"

static int rooms_count(t_room *room)
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

void init_viz(t_viz *viz, t_room *room)
{
	SDL_DisplayMode	dm;

	if (SDL_Init(SDL_INIT_EVERYTHING))
		viz_error(viz);
	if (SDL_GetCurrentDisplayMode(0, &dm))
		viz_error(viz);
	viz->win_w = dm.w / 2;
	viz->win_h = dm.h / 2;
	viz->rad = viz->win_w * viz->win_h / rooms_count(room);
	if (!(viz->window = SDL_CreateWindow("a", 40, 40, viz->win_w, viz->win_h,
			SDL_WINDOW_SHOWN)))
		viz_error(viz);
	if (!(viz->renderer = SDL_CreateRenderer(viz->window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		viz_error(viz);
}

void	drawing_all(t_grp grp, t_viz vz)
{
	draw_field(grp, vz);
}

void	draw_field(t_grp grp, t_viz vz)
{
	t_room	*room;
	int		offset;

	room = grp.room;
	while (room)
	{
		handle_events();
		SDL_RenderClear(vz.renderer);
		SDL_SetRenderDrawColor(vz.renderer, 0, 0, 0, 0);
		SDL_RenderClear(vz.renderer);
		if (room->x > vz.win_w / 2)
			offset = -vz.rad;
		else
			offset = vz.rad;
		if (room == grp.start)
			aacircleRGBA(vz.renderer, room->x + 100, room->y + 100, vz.rad, 0, 0xFF, 0, 0xFF);
		else if (room == grp.end)
			aacircleRGBA(vz.renderer, room->x + 100, room->y + 100, vz.rad, 0, 0, 0xFF, 0xFF);
		else
			aacircleRGBA(vz.renderer, room->x + 100, room->y + 100, vz.rad, 0xFF, 0, 0, 0xFF);
		room = room->next;
	}
	SDL_RenderPresent(vz.renderer);
	SDL_Delay(10000);
}

void	make_vizual(t_viz *vz, t_grp grp)
{
	init_viz(vz, grp.room);
	drawing_all(grp, *vz);
}

/*int 	main()
{
	t_viz	vz;
	_Bool	run = 1;

	init_viz(&vz);
	while (run)
	{
		handle_events(&vz, &run);
		SDL_RenderClear(vz.renderer);
		SDL_SetRenderDrawColor(vz.renderer, 0, 0, 0, 0);
		SDL_RenderClear(vz.renderer);
		//SDL_SetRenderDrawColor(vz.renderer, 0xFF, 0, 0, 0xFF);
		//SDL_RenderDrawLine(vz.renderer, 40, 40, 200, 200);
		aacircleRGBA(vz.renderer, vz.win_w / 2, vz.win_h / 2, 100, 0, 0xFF, 0, 0xFF);
		SDL_RenderPresent(vz.renderer);
	}
	quit_viz(&vz);
}*/
