/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizual_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 23:37:32 by ylila             #+#    #+#             */
/*   Updated: 2020/02/14 23:42:09 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	set_action(t_viz *vz, uint8_t go_end)
{
	vz->action.go_to_end = go_end;
}
