/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ant_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 23:37:04 by ylila             #+#    #+#             */
/*   Updated: 2020/02/14 23:37:06 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizual.h"

int		get_start_ants(t_way *ways)
{
	int	ants;

	ants = 0;
	while (ways)
	{
		if (ways->open)
			ants += ways->ants;
		ways = ways->next;
	}
	return (ants);
}
