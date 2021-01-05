/*
** EPITECH PROJECT, 2020
** mylib
** File description:
** delete double linked list
*/

#include <stdlib.h>
#include "my_dlist.h"

void delete_node_from_dlist(dlist_t *node)
{
    dlist_t *prev = node->prev;
    dlist_t *next = node->next;

    prev->next = next;
    next->prev = prev;
    free(node);
}

void delete_data_from_dlist(dlist_t *root, void *data)
{
    dlist_t *node = root->next;
    dlist_t *prev;
    dlist_t *next;

    while (node && node != root) {
        if (node->data == data) {
            prev = node->prev;
            next = node->next;
            prev->next = next;
            next->prev = prev;
            free(node);
            return;
        }
        node = node->next;
    }
}