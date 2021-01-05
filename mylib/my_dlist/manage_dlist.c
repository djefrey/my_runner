/*
** EPITECH PROJECT, 2020
** mylib
** File description:
** create double linked list
*/

#include <stdlib.h>
#include "my_dlist.h"


char add_element_to_dlist(dlist_t *root, void *data)
{
    dlist_t *first = NULL;
    dlist_t *new = malloc(sizeof(dlist_t));

    if (!new)
        return (1);
    new->data = data;
    first = root->next;
    new->next = first;
    new->prev = root;
    root->next = new;
    first->prev = new;
    return (0);
}

char add_element_to_end_dlist(dlist_t *root, void *data)
{
    dlist_t *end = NULL;
    dlist_t *new = malloc(sizeof(dlist_t));

    if (!new)
        return (1);
    new->data = data;
    end = root->prev;
    new->prev = end;
    new->next = root;
    root->prev = new;
    end->next = new;
    return (0);
}

dlist_t *clone_dlist(dlist_t *ori, char inverse)
{
    dlist_t *clone = create_dlist();
    dlist_t *list = ori->next;

    while (list != ori) {
        if (inverse)
            add_element_to_dlist(clone, list->data);
        else
            add_element_to_end_dlist(clone, list->data);
        list = list->next;
    }
    return (clone);
}

dlist_t *create_dlist(void)
{
    dlist_t *dlist = malloc(sizeof(dlist_t));

    if (!dlist)
        return (NULL);
    dlist->prev = dlist;
    dlist->next = dlist;
    dlist->data = 0;
    return (dlist);
}