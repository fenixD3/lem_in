//
// Created by Mort Deanne on 14/01/2020.
//

#include "includes/lem_in.h"

#include <stdio.h>
#include <ways_and_ants.h>


void 	print_rooms(t_room *room)
{
	t_link *linkk;
	while (room)
	{
		linkk = room->link;
		printf("%s:  ", room->name);
		while(linkk)
		{
			printf("%s -> ", linkk->room->name);
			linkk = linkk->next;
		}
		printf("\n");
		room = room->next;
	}
}

void print_links(t_grp *grp, t_room *room, char wich_node, char rule)
{
	int i = 0;
	int j = 0;

	printf("\n");
	t_link *link;
	if (wich_node == 's')
	{
		printf("Start node: ");
		link = grp->start->link;
	}
	else if (wich_node == 'e')
	{
		printf("End node:   ");
		link = grp->end->link;
	}
	else
	{
		printf("node %s: ", room->name);
		link = room->link;
	}
	printf("name:depth:way_number  ");
	while (link)
	{
		if (rule == 'a' || link->room->way_nu)
		{
			printf("%s:%d:%d  ", link->room->name, link->room->depth,link->room->way_nu);
			j++;
		}
		link = link->next;
		i++;
	}
	printf("\nlinks: %d Ways: %d\n-------------------------\n", i, j);
}

void print_links_node_by_name(char *name, t_room *room, int need_all)
{
	char c = 'b';
	while (room && strcmp(name, room->name))
		room = room->next;
	if (need_all)
		c = 'a';
	if (!room)
		printf("No name found\n");
	else
		print_links(NULL, room, c, c);
}

void	print_rooms_with_depth(t_room *start)
{
	while (start)
	{
		printf("%s : %d\n", start->name, start->depth);
		start = start->next;
	}
	printf("--------------\n");
}

void print_rooms_with_depth_and_way(t_room *room, t_room *this_room)
{
	printf("name : depth : way_number\n");
	while (room)
	{
		printf("%s\t%d\t", room->name, room->depth);
		if (room->way_nu)
			printf("%d  ", room->way_nu);
		else
			printf("   ");
		if (this_room && this_room == room)
		{
			printf(" -> ");
			///print_links(room, NULL, 0, 0);
		}
		else
			printf("\n");
		room = room->next;
	}
	printf("--------------\n");
}

void	print_way(t_room *room, t_grp *grp)
{
	int way_num = room->way_nu;
	t_link	*link;
	t_room	*prev;
	int i = 0;

	link = room->link;
	prev = room;
	printf("Way: %d\n%s <- ", room->way_nu, grp->end->name);
	while (link->room != grp->start)
	{
		if (i == 26)
			i = i;


		printf("%s:%d <- ", room->name, room->depth);
		i++;
		while (link)
		{
			if ((link->room->way_nu == way_num && link->room != prev) || link->room == grp->start)
				break ;
			link = link->next;
		}

		if (!link)
		{
			printf("ALARM\n");
			return ;
		}
		else if (link->room == grp->start)
		{
			printf("%s\n", link->room->name);
			i++;
			printf("Nodes: %d\n", i);
			return ;
		}
		prev = room;
		room = link->room;
		link = room->link;
	}
	printf("%s\nNodes: %d\n", link->room->name, i);
}

void	print_ways(t_grp *grp)
{
	t_room *end;
	t_link *link;

	end = grp->end;
	link = end->link;
	while (link)
	{

		if (link->room->way_nu)
		{
			printf("------------\n");
			print_way(link->room, grp);
			printf("------------\n");
		}
		link = link->next;
	}
}

void	print_seted_way_number(t_room *room)
{
	t_link *link;
	link = room->link;
	while (link)
	{
		if (link->room->way_nu)
			printf("%d ", link->room->way_nu);
		else
			printf("-");
		link = link->next;
	}
	printf("\n");
}

void	make_names_aroud_start_end_better(t_grp *grp)
{
	ft_strncpy(grp->start->name, "strt", 100);
	ft_strncpy(grp->end->name, "end", 100);
	int i = 1;
	t_link *link = grp->start->link;
	while (link)
	{
		link->room->name[0] = 's';
		ft_strncpy(link->room->name + 1, ft_itoa(i), 100);
		i++;
		link = link->next;
	}
	i = 1;
	link = grp->end->link;
	while (link)
	{
		link->room->name[0] = 'e';
		ft_strncpy(link->room->name + 1, ft_itoa(i), 100);
		i++;
		link = link->next;
	}
}

void    print_arr_of_combinations(int len_way1, int len_way2, int num_ants)
{
	int i = 0;
	int j = 0;
    int tmp1;
    int tmp2;


	j = 0;
	while (j < len_way2 * 2)
	{
	    i = 0;
        printf("%d\t|\t", j);
		while (i++ < num_ants)
		{
		    tmp1 = len_way1 - 1 + i - j - 1;
		    tmp2 = len_way2 - 1 + i - 1;
            printf("%d\t", (tmp1 > tmp2) ? tmp1 : tmp2);
		}
	    printf("\n");
		j++;
	}
}

void print_ants_ways(t_way *way, int ants, int clear)
{
	printf("\nPrint for %d\nway_nu : depth : ants\n", ants);
	while (way)
	{
		printf("%d\t%d\t%d\n", way->room->way_nu, way->room->depth, way->ants);
		if (clear)
		{
			way->ants = 0;
			way->open = 0;
		}
		way = way->next;
	}
}

void	print_ants(t_ant *ant)
{
	while (ant)
	{
		printf("%d %s\n", ant->number, ant->room->name);
		ant = ant->next;
	}
	printf("------------------\n");
}
