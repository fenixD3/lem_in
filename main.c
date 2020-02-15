/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:25:57 by mdeanne           #+#    #+#             */
/*   Updated: 2020/02/14 23:34:32 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/lem_in.h"
#include "ways_and_ants.h"
#include "vizual.h"

static void	grp_flg_init(t_grp *grp, const int ac, char **av, t_viz *vz)
{
	grp->room = NULL;
	grp->start = NULL;
	grp->end = NULL;
	vz->flg = 0;
	if (ac == 1)
		return ;
	if (!ft_strcmp(av[1], "-v"))
		vz->flg |= FLG_VZ;
}

int			main(int ac, char **av)
{
	t_grp	grp;
	t_way	*ways;
	t_fline	*flist;
	int		ants;
	t_viz	vz;

	grp_flg_init(&grp, ac, av, &vz);
	flist = making_lists(&grp, &ants);
	if (!is_one_step_way(&grp))
		finding_ways(&grp);
	if (!check_ways(grp.start->link))
		go_exit("ERROR: there is no way from start to end");
	ways = count_ants_for_way(grp.start->link, &grp, ants);
	vz.flg ? init_viz(&vz, grp.room) : 0;
	while (flist)
	{
		ft_putendl(flist->line);
		flist = flist->next;
	}
	ft_putchar('\n');
	put_ants_steps(ways, &grp, &vz);
	vz.flg ? quit_viz(&vz) : 0;
	exit(0);
}
