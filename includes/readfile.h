/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:27:39 by mdeanne           #+#    #+#             */
/*   Updated: 2020/02/04 18:27:41 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READFILE_H
# define READFILE_H

typedef struct	s_fline
{
	char			*line;
	struct s_fline	*next;
}				t_fline;

t_fline			*read_and_save_file(int fd);

#endif
