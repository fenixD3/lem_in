//
// Created by Mort Deanne on 27/01/2020.
//

#include <libft.h>



int check_room(char *line)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strchr(line, ' ');
	while (*tmp)
	{
		i++;
		tmp++;
		while (*tmp && ft_isdigit(*tmp))
			tmp++;
		if ((*tmp != ' ' || !*tmp) && i > 2)
			go_exit(4);
	}
	if (i != 2)
		go_exit(4);

	return (1);
}