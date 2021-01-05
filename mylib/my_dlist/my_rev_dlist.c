/*
** EPITECH PROJECT, 2020
** mylib
** File description:
** rev double linked list
*/

#include "my_dlist.h"

void my_rev_dlist(dlist_t *root)
{
    dlist_t *node = root->next;
    dlist_t *prev;

    while (node && node != root) {
        prev = node->prev;
        node->prev = node->next;
        node->next = prev;
        node = node->prev;
    }
    prev = root->prev;
    root->prev = root->next;
    root->next = prev;
}