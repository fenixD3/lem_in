//
// Created by Yeste Lila on 05/02/2020.
//

#include "vizual.h"
#include "ways_and_ants.h"

void	make_vizual(t_viz *vz, t_grp grp)
{
	init_viz(vz, grp.room);
	draw_field(grp, *vz);
}

void	draw(t_grp *grp, t_viz *vz, t_ant *ant, int ants_cnt)
{
	handle_events();
	SDL_SetRenderDrawColor(vz->renderer, 0, 0, 0, 0);
	SDL_RenderClear(vz->renderer);
	draw_field(*grp, *vz);
	if (vz->action.define_start)
		define_start_ants(grp->start, vz, ants_cnt);
	if (vz->action.go_to_end)
		first_go_ants_to_exit(grp, vz, ants_cnt);
	if (!vz->action.go_to_end && !vz->action.define_start)
		draw_ant_step(ant, vz);
	SDL_RenderPresent(vz->renderer);
	SDL_Delay(1000);
}

void	init_viz(t_viz *viz, t_room *room)
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
	if (!(viz->ants = SDL_CreateTexture(viz->renderer,
			SDL_GetWindowPixelFormat(viz->window),
			SDL_TEXTUREACCESS_TARGET, viz->win_w, viz->win_h)))
		viz_error(viz);
	get_scale_offset(viz, room);
}

void	draw_field(t_grp grp, t_viz vz)
{
	t_room	*room;

	room = grp.room;
	/*SDL_SetRenderDrawColor(vz.renderer, 0, 0, 0, 0);
	SDL_RenderClear(vz.renderer);*/
	while (room)
	{
//		handle_events();
		get_center(&vz, room);
		if (room == grp.start)
			aacircleRGBA(vz.renderer, room->cent_x, room->cent_y,
					vz.diam / 2, 0, 0xFF, 0, 0xFF);
		else if (room == grp.end)
			aacircleRGBA(vz.renderer, room->cent_x, room->cent_y,
						 vz.diam / 2, 0, 0, 0xFF, 0xFF);
		else
			aacircleRGBA(vz.renderer, room->cent_x, room->cent_y,
						 vz.diam / 2, 0xFF, 0, 0, 0xFF);
		room = room->next;
	}
	draw_links(grp, vz);
	/*SDL_RenderPresent(vz.renderer);
	SDL_Delay(2000);*/
}

void	draw_links(t_grp grp, t_viz vz)
{
	t_room	*room;
	t_link	*connect;

	room = grp.room;
	while (room)
	{
//		handle_events();
		connect = room->link;
		while (connect)
		{
			if ((room->way_nu > 0 || room == grp.start || room == grp.end)
				&& connect->room->way_nu > 0)
					thickLineRGBA(vz.renderer, room->cent_x, room->cent_y,
						connect->room->cent_x, connect->room->cent_y, 2,
						0xFF, 0, 0xFF, 0xFF);
			else
				thickLineRGBA(vz.renderer, room->cent_x, room->cent_y,
					connect->room->cent_x, connect->room->cent_y, 2,
					0xFF, 0xFF, 0, 0x32);
			connect = connect->next;
		}
		room = room->next;
	}
}
