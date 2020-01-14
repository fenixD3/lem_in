//
// Created by Mort Deanne on 11/01/2020.
//

#ifndef MEMLIST_H
#define MEMLIST_H
#include <stdlib.h>

/*
** ml is acronym for words "memory list"
*/

void			*ml_malloc(size_t size);
void			ml_free(void *ptr);
void			ml_free_all(void);

#endif

