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
