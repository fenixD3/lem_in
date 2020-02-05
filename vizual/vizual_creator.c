//
// Created by Yeste Lila on 05/02/2020.
//

#include "vizual.h"
#include "lem_in.h"

void	init_viz(t_viz *viz)
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
}

int 	main()
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
		SDL_SetRenderDrawColor(vz.renderer, 0xFF, 0, 0, 0xFF);
		//SDL_RenderDrawLine(vz.renderer, 40, 40, 200, 200);
		aacircleColor(vz.renderer, vz.win_w / 2, vz.win_h / 2, 100, 0xFF0000FF);
		SDL_RenderPresent(vz.renderer);
	}
	quit_viz(&vz);
}