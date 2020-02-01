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

#include <libft.h>
#include "../../mdeanne2/includes/ft_stack.h"
#include "../../mdeanne2/includes/checker.h"

void go_exit(char *error)
{
	if (error)
		ft_putendl(error);
	exit(1);
}
