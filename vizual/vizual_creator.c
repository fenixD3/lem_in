//
// Created by Yeste Lila on 05/02/2020.
//

#include "vizual.h"
#include "ways_and_ants.h"

void	make_vizual(t_viz *vz, t_grp grp)
{
	init_viz(vz, grp.room);
	draw_field(grp, *vz);
	draw_links(grp, *vz);
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
	if (!(viz->window = SDL_CreateWindow("a", 40, 40, viz->win_w, viz->win_h,
			SDL_WINDOW_SHOWN)))
		viz_error(viz);
	if (!(viz->renderer = SDL_CreateRenderer(viz->window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		viz_error(viz);
	viz->diam = get_diam(viz->win_w, viz->win_h, room);
	if (!(viz->ants = SDL_CreateTexture(viz->renderer, SDL_GetWindowPixelFormat(viz->window),
			SDL_TEXTUREACCESS_TARGET, viz->win_w, viz->win_h)))
		viz_error(viz);
	if (!(viz->black = SDL_CreateTexture(viz->renderer, SDL_GetWindowPixelFormat(viz->window),
			SDL_TEXTUREACCESS_TARGET, viz->win_w, viz->win_h)))
		viz_error(viz);
	get_scale_offset(viz, room);
}

void	draw_field(t_grp grp, t_viz vz)
{
	t_room	*room;

	room = grp.room;
	SDL_SetRenderDrawColor(vz.renderer, 0, 0, 0, 0);
	SDL_RenderClear(vz.renderer);
	while (room)
	{
		handle_events();
		get_center(&vz, room);
		if (room == grp.start)
			aacircleRGBA(vz.renderer, room->cent_x,//vz.cent_x,//room->x + vz.offset_x,
						 room->cent_y,//vz.cent_y,//room->y + vz.offset_y,
						 vz.diam / 2, 0, 0xFF, 0, 0xFF);
		else if (room == grp.end)
			aacircleRGBA(vz.renderer, room->cent_x,//vz.cent_x,//room->x + vz.offset_x,
						 room->cent_y,//vz.cent_y,//room->y + vz.offset_y,
						 vz.diam / 2, 0, 0, 0xFF, 0xFF);
		else
			aacircleRGBA(vz.renderer, room->cent_x,//vz.cent_x,//room->x + vz.offset_x,
						 room->cent_y,//vz.cent_y,//room->y + vz.offset_y,
						 vz.diam / 2, 0xFF, 0, 0, 0xFF);
		stringRGBA(vz.renderer, room->cent_x + 10, room->cent_y + 10, room->name, 0xFF, 0, 0, 0xFF);
		room = room->next;
	}
	SDL_RenderPresent(vz.renderer);
	SDL_Delay(2000);
}

void	draw_links(t_grp grp, t_viz vz)
{
	t_room	*room;
	t_link	*connect;

	room = grp.room;
	while (room)
	{
		handle_events();
		connect = room->link;
		while (connect)
		{
			if ((room->way_nu > 0 || room == grp.start || room == grp.end)
				&& connect->room->way_nu > 0)
				/*aalineRGBA(vz.renderer, room->cent_x, room->cent_y,
						   connect->room->cent_x, connect->room->cent_y,
						   0xFF, 0, 0xFF, 0xFF);*/
				thickLineRGBA(vz.renderer, room->cent_x, room->cent_y,
					connect->room->cent_x, connect->room->cent_y, 2,
					0xFF, 0, 0xFF, 0xFF);
			else
				/*aalineRGBA(vz.renderer, room->cent_x, room->cent_y,
						   connect->room->cent_x, connect->room->cent_y,
						   0xFF, 0xFF, 0, 0xFF);*/
				thickLineRGBA(vz.renderer, room->cent_x, room->cent_y,
					connect->room->cent_x, connect->room->cent_y, 2,
					0xFF, 0xFF, 0, 0x32);
			connect = connect->next;
		}
		room = room->next;
	}
	SDL_RenderPresent(vz.renderer);
	SDL_Delay(2000);
}

/*int 	main(int ac, char **av)
{
	t_viz	vz;
	_Bool	run = 1;

	init_viz(&vz, NULL);
	while (run)
	{
		handle_events(&vz, &run);
		*//*SDL_RenderClear(vz.renderer);
		SDL_SetRenderDrawColor(vz.renderer, 0, 0, 0, 0);
		SDL_RenderClear(vz.renderer);*//*
		*//*SDL_SetRenderDrawColor(vz.renderer, 0xFF, 0, 0, 0xFF);
		SDL_RenderDrawLine(vz.renderer, 40, 40, 200, 200);*//*
		*//*aalineRGBA(vz.renderer, 40, 40, 100, 100, 0xFF, 0, 0, 0xFF);
		aacircleRGBA(vz.renderer, vz.win_w / 2, vz.win_h / 2, 100, 0, 0xFF, 0, 0xFF);*//*

		//SDL_SetTextureBlendMode(vz.ants, SDL_BLENDMODE_NONE);

		SDL_SetRenderTarget(vz.renderer, vz.ants);
		SDL_SetRenderDrawBlendMode(vz.renderer, SDL_BLENDMODE_NONE);
		SDL_RenderCopy(vz.renderer, vz.ants, NULL, NULL);
		filledCircleRGBA(vz.renderer, 40, 40, 5, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderPresent(vz.renderer);
	}
	quit_viz(&vz);
}*/
