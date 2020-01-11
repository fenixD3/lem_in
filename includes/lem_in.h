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



typedef struct	s_room
{
	int				x;
	int				y;
	struct s_link	*link;
}				t_room;

typedef struct	s_link
{
	t_room			*room;
	struct s_link	*next;
}				t_link;

#endif
