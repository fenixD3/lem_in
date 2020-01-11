//
// Created by Mort Deanne on 11/01/2020.
//

#include "blackbox_memlist.h"

t_ml	*ml_create(void *ptr)
{
	t_ml *new;

	new = NULL;
	if (!(new = (t_ml*)malloc(sizeof(t_ml))))
		return (NULL);
	new->data = ptr;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}


_Bool		ml_push_front(t_ml **head, t_ml *new)
{
	if (!new)
	{
		ml_clear_lst(head);
		return (0);
	}
	if (head && *head)
	{
		new->next = *head;
		(*head)->prev = new;
	}
	*head = new;
	return (1);
}

#include "memlist.h"
#include "../includes/lem_in.h"

int 	main(void)
{
	int *i;
	int *j;

	i = (int*)ml_malloc(sizeof(int));
	*i = 5;
	i = (int*)ml_malloc(sizeof(int));
	*i = 6;
	j = i;
	i = (int*)ml_malloc(sizeof(int));
	*i = 7;
	i = (int*)ml_malloc(sizeof(int));
	*i = 8;
	i = (int*)ml_malloc(sizeof(int));
	*i = 9;
	i = (int*)ml_malloc(sizeof(int));
	*i = 10;
	i = (int*)ml_malloc(sizeof(int));
	*i = 11;
	i = (int*)ml_malloc(sizeof(int));
	*i = 12;

	ml_free(j);

	ml_free_all();
	return (0);
}