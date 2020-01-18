/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:27:04 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/11 17:27:06 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H
#include "libft.h"
#include "../read_and_check/readfile.h"


typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	struct s_link	*link;
	struct s_room	*next;
	int 			depth;
	int 			way_number;
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

void making_lists(t_grp *grp);
t_room *making_rooms_and_links(t_fline *head, t_grp *grp);

void 	finding_ways(t_grp *grp);
int		set_and_go_back(t_room *room, t_grp *grp);
void	clear_nonwayed_nodes_depth(t_room *room);


///
void 	print_rooms(t_room *room);
void	print_rooms_with_depth(t_room *start);
void	print_ways(t_grp *grp);
void	print_seted_way_number(t_room *room);
void	print_rooms_with_depth_and_way(t_room *room, t_room *this_room);
void	print_links(t_grp *grp, t_room *room, char wich_node, char rule);
void print_links_node_by_name(char *name, t_room *room, int need_all);

void	make_names_aroud_start_end_better(t_grp *grp);

#endif
