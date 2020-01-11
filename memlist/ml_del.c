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
	return (1);
}

void		ml_delelem(t_ml **head, t_ml *delelem)/// не работатет передача указателя!!
{
	if (*head == delelem)
		*head = (*head)->next;
	else
	{
		delelem->prev->next = delelem->next;
		if (delelem->next)
			delelem->next->prev = delelem->prev;
	}
	free(delelem->data);
	free(delelem);
}