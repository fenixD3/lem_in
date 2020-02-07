//
// Created by Yeste Lila on 05/02/2020.
//

#ifndef VIZUAL_H
# define VIZUAL_H

# include "lem_in.h"
# include <SDL.h>
# include <SDL2_gfxPrimitives.h>

# define RAD 50

typedef struct	s_viz
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	Sint16			win_w;
	Sint16			win_h;
	Sint16			offset_x;
	Sint16			offset_y;
	Sint16 			diam;
}				t_viz;

void	make_vizual(t_viz *vz, t_grp grp);
void	quit_viz(t_viz *viz);
void	viz_error(t_viz *viz);
void	handle_events();
void	init_viz(t_viz *viz, t_room *room);
void	drawing_all(t_grp grp, t_viz vz);
void	draw_field(t_grp grp, t_viz vz);

Sint16	get_diam(int win_w, int win_h, t_room *room);
int		rooms_count(t_room *room);
void	get_offset(t_viz *vz, t_room *room);

#endif
