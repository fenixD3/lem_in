//
// Created by Mort Deanne on 11/01/2020.
//

#include "blackbox_memlist.h"

_Bool		ml_clear_lst(t_ml **head)
{
	t_ml *prev;

	if (!head || !*head)
		return (0);
	prev = *head;
	*head = (*head)->next;
	while (*head != NULL)
	{
		free(prev->data);
		free(prev);
		prev = *head;
		*head = (*head)->next;
	}
	free(prev->data);
	free(prev);
	return (1);
}

void		ml_delelem(t_ml **head, void *ptr)/// не работатет передача указателя!!
{
	t_ml *tmp;

	tmp = *head;
	if (tmp->data == ptr)
		*head = (*head)->next;
	else
	{
		while (tmp->data != ptr)
			tmp = tmp->next;
		tmp->prev->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = tmp->prev;
	}
	free(tmp->data);
	free(tmp);
}