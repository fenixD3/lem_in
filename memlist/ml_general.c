//
// Created by Mort Deanne on 11/01/2020.
//

#include "blackbox_memlist.h"

static _Bool 	ml_static_list(void *ptr, int rule)
{
	static t_ml *head;

	if (rule == ML_MALLOC)
	{
		if (!ml_push_front(&head, ml_create(ptr)))
			return (0);
	}
	else if (rule == ML_DELELEM)
		ml_delelem(&head, ptr); //// так как мы сохранили указатель на память в виде последнего элемента, он хранит другой next!!??
	else if (rule == ML_CLEARLIST)
		ml_clear_lst(&head);
}

void			*ml_malloc(size_t size)
{
	void *data;

	if (!(data = malloc(size)))
	{
		ml_static_list(NULL, ML_CLEARLIST);
		return NULL;
	}
	ml_static_list(data, ML_MALLOC);
	return (data);
}

void			ml_free(void *ptr)
{
	ml_static_list(ptr, ML_DELELEM);
}

void			ml_free_all(void)
{
	ml_static_list(NULL, ML_CLEARLIST);
}