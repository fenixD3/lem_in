//
// Created by Yeste Lila on 05/02/2020.
//

#ifndef VIZUAL_H
# define VIZUAL_H

# include "lem_in.h"
# include <SDL.h>
# include <SDL2_gfxPrimitives.h>

typedef struct	s_viz
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	int				win_w;
	int				win_h;
	int				offset;
	int 			rad;
}				t_viz;

void	make_vizual(t_viz *vz, t_grp grp);
void	quit_viz(t_viz *viz);
void	viz_error(t_viz *viz);
void handle_events();
void init_viz(t_viz *viz, t_room *room);
void	drawing_all(t_grp grp, t_viz vz);
void	draw_field(t_grp grp, t_viz vz);

#endif
