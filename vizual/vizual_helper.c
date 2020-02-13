//
// Created by Yeste Lila on 05/02/2020.
//

#include "vizual.h"

void	quit_viz(t_viz *viz)
{
	SDL_DestroyTexture(viz->ants);
	SDL_DestroyRenderer(viz->renderer);
	viz->renderer = NULL;
	SDL_DestroyWindow(viz->window);
	viz->window = NULL;
	SDL_Quit();
}

void	viz_error(t_viz *viz)
{
	const char	*sdl_error;

	sdl_error = SDL_GetError();
	write(1, "SDL_Error: ", 11);
	write(1, sdl_error, 10);
	quit_viz(viz);
	exit(1);
}

void	handle_events(void)
{
	SDL_Event	ev;

	SDL_PollEvent(&ev);
	if (ev.type == SDL_QUIT)
		;
}
