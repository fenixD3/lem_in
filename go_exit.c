/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:36:04 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/04 18:36:07 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mdeanne2/includes/ft_stack.h"
#include "../../mdeanne2/includes/checker.h"

void go_exit(int ko, char *error)
{
	if (ko == 2)
		ft_putendl("KO");
	else if (ko == 1)
		ft_putendl("ERROR");
	else if (ko == 3)
		ft_putendl("ERROR: in read_and_check file");
	else if (ko == 4)
		ft_putendl("ERROR: file contains invalid room");
	else if (ko == 5)
		ft_putendl("ERROR: room name contains '-'");
	else if (ko == 6)
		ft_putendl("ERROR: invalid ants representation");
	else if (ko == 7)
		ft_putendl("ERROR: more than one ants record");
	else if (ko == 8)
		ft_putendl("ERROR: link has identical rooms");
	else if (ko == 9)
		ft_putendl("ERROR: wrong order in file");
	else if (ko == 10)
		ft_putendl("ERROR: file not contains rooms");
	else if (ko > 10)
		ft_putendl(error);
	exit(1);
}
