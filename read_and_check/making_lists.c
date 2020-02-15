/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:27:16 by mdeanne           #+#    #+#             */
/*   Updated: 2020/02/14 23:35:58 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readfile.h"
#include "libft.h"
#include "lem_in.h"
#include <fcntl.h>

t_fline	*making_lists(t_grp *grp, int *ants)
{
	t_fline	*fileline;
	t_fline *tmp;

	fileline = read_and_save_file(0);
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
