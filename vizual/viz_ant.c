//
// Created by da.filiptsev on 13.02.2020.
//

#include "vizual.h"

void	draw_ant_step(t_ant *ant, t_viz *vz)
{
	SDL_Rect	rect;

	SDL_SetTextureColorMod(vz->ants, 0, 0, 0);
	rect = get_rect_for_texture(ant->prev_room, vz->diam);
	SDL_RenderCopy(vz->renderer, vz->ants, &rect, &rect);
	SDL_SetTextureColorMod(vz->ants, 0xFF, 0xFF, 0xFF);
	rect = get_rect_for_texture(ant->room, vz->diam);
	SDL_RenderCopy(vz->renderer, vz->ants, NULL, &rect);
	filledCircleRGBA(vz->renderer, ant->room->cent_x, ant->room->cent_y,
					 vz->diam / 3, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderPresent(vz->renderer);
	SDL_Delay(1000);
}

SDL_Rect get_rect_for_texture(t_room *room, Sint16 diam)
{
	SDL_Rect	rect;

	rect.x = room->cent_x;
	rect.y = room->cent_y;
	rect.w = diam / 3;
	rect.h = diam / 3;
	return (rect);
}

void	define_start_ants(t_room *start, t_viz *vz, int ants_cnt)
{
	SDL_Rect rect;

	rect = get_rect_for_texture(start, vz->diam);
	SDL_RenderCopy(vz->renderer, vz->ants, NULL, &rect);
	while (ants_cnt--)
		filledCircleRGBA(vz->renderer, start->cent_x, start->cent_y,
			vz->diam / 3, 0xFF, 0xFF, 0xFF, 0xFF);
	/*SDL_RenderPresent(vz->renderer);
	SDL_Delay(1000);*/
}

void	first_go_ants_to_exit(t_grp *grp, t_viz *vz, int ants_cnt)
{
	SDL_Rect rect;

	rect = get_rect_for_texture(grp->start, vz->diam);
	SDL_RenderCopy(vz->renderer, vz->ants, &rect, &rect);
	SDL_SetTextureColorMod(vz->ants, 0xFF, 0xFF, 0xFF);
	rect = get_rect_for_texture(grp->end, vz->diam);
	SDL_RenderCopy(vz->renderer, vz->ants, NULL, &rect);
	while (ants_cnt--)
	{
		filledCircleRGBA(vz->renderer, grp->end->cent_x, grp->end->cent_y,
			vz->diam / 3, 0xFF, 0xFF, 0xFF, 0xFF);
		/*SDL_RenderPresent(vz->renderer);
		SDL_Delay(1000);*/
	}
}
