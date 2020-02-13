/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:27:16 by mdeanne           #+#    #+#             */
/*   Updated: 2020/02/04 18:27:18 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readfile.h"
#include "libft.h"
#include "lem_in.h"

#include <fcntl.h>

t_fline		*making_lists(t_grp *grp, int *ants)
{
	t_fline	*fileline;
	t_fline *tmp;

	///////////
	int fd = 0;
	if ((fd = open("/Users/ylila/Desktop/Archive/lem-in_maps/map_6", O_RDONLY)) < 0)
		go_exit("ERROR: in read_and_check file");
	///////////
	fileline = read_and_save_file(fd);
	grp->room = making_rooms_and_links(fileline, grp);
	if (!grp->start && !grp->end)
		go_exit("ERROR: file doesn't contain ##start and ##end nodes");
	if (!grp->start)
		go_exit("ERROR: file doesn't contain ##start node");
	if (!grp->end)
		go_exit("ERROR: file doesn't contain ##end node");
	tmp = fileline;
	while (tmp->line[0] == '#')
		tmp = tmp->next;
	*ants = ft_atoi(tmp->line);
	return (fileline);
}
