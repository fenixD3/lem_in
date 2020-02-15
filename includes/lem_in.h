/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:27:04 by mdeanne           #+#    #+#             */
/*   Updated: 2020/02/14 23:33:40 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "readfile.h"
# include <stdint.h>

typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	struct s_link	*link;
	struct s_room	*next;
	int				depth;
	int				way_nu;
	int16_t			cent_x;
	int16_t			cent_y;
}				t_room;

typedef struct	s_link
{
	t_room			*room;
	struct s_link	*next;
}				t_link;

typedef struct	s_group
{
	t_room *start;
	t_room *end;
	t_room *room;
}				t_grp;

void			push_room(t_room **head, char *line);
void			add_links(t_room *head, char *line);

void			go_exit(char *error);

t_fline			*making_lists(t_grp *grp, int *ants);
t_room			*making_rooms_and_links(t_fline *head, t_grp *grp);

void			finding_ways(t_grp *grp);
void			marking_list(t_grp *grp);
void			set_start_depth(t_grp *grp);
void			clear_nonwayed_nodes_depth(t_room *room);
int				is_one_step_way(t_grp *grp);

/*
** check
*/

int				type_of_line(char *line);
int				check_valid_line(char *line);
_Bool			check_ways(t_link *link);
void			check_rooms_duplicates(t_room *head);

#endif
