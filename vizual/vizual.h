//
// Created by Yeste Lila on 05/02/2020.
//

#ifndef VIZUAL_H
# define VIZUAL_H

# include <SDL.h>
# include <SDL2_gfxPrimitives.h>

typedef struct	s_viz
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	int				win_w;
	int				win_h;
}				t_viz;

void	quit_viz(t_viz *viz);
void	viz_error(t_viz *viz);
void	handle_events(t_viz *viz, _Bool *run);
void	init_viz(t_viz *viz);

#endif
