//
// Created by Yeste Lila on 05/02/2020.
//

#ifndef VIZUAL_H
# define VIZUAL_H

# include "lem_in.h"
#include "ways_and_ants.h"
# include <SDL.h>
# include <SDL2_gfxPrimitives.h>
# include "libft.h"

# define RAD 50

/*
** cent_x & cent_y calculate for every room
*/

typedef struct	s_viz
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*ants;
	SDL_Texture		*black;
	Sint16			win_w;
	Sint16			win_h;
	Sint16			offset_x;
	Sint16			offset_y;
	double			scale_x;
	double			scale_y;
	Sint16 			diam;
}				t_viz;

void	make_vizual(t_viz *vz, t_grp grp);
void	quit_viz(t_viz *viz);
void	viz_error(t_viz *viz);
void	handle_events();
void	init_viz(t_viz *viz, t_room *room);
void	draw_field(t_grp grp, t_viz vz);
void	draw_links(t_grp grp, t_viz vz);

Sint16	get_diam(int win_w, int win_h, t_room *room);
void	get_scale_offset(t_viz *vz, t_room *room);
void	get_center(t_viz *vz, t_room *curr_room);

void	define_start_ants(t_room *start, t_viz *vz, int ants_cnt);
void	draw_ant_step(t_ant *ant, t_viz *vz);
SDL_Rect get_rect_for_texture(t_room *room, Sint16 diam);
void	first_go_ants_to_exit(t_grp *grp, t_viz *vz, int ants_cnt);

#endif
