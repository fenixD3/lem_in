/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_and_ants.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:28:39 by mdeanne           #+#    #+#             */
/*   Updated: 2020/02/04 18:28:41 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAYS_AND_ANTS_H
# define WAYS_AND_ANTS_H

# include "lem_in.h"
# include "ft_ptintf.h"

typedef struct	s_way
{
	t_room			*room;
	int				ants;
	_Bool			open;
	struct s_way	*next;
}				t_way;

typedef struct	s_ant
{
	t_room			*room;
	t_room			*prev_room;
	int				number;
	struct s_ant	*next;
}				t_ant;

void			push_way(t_way **head, t_room *room);
t_way			*make_way_list(t_link *link, int max_way_num);
t_way			*count_ants_for_way(t_link *link, t_grp *grp, int ants);
t_room			*find_next_room(t_ant *ant, t_grp *grp);
void			kill_ants(t_ant **head, t_room *end);

#endif
