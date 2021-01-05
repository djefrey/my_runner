/*
** EPITECH PROJECT, 2020
** mylib
** File description:
** double linked list
*/

#ifndef MY_DLIST_H_
#define MY_DLIST_H_

typedef struct dlist {
    struct dlist *prev;
    struct dlist *next;
    void *data;
} dlist_t;

char add_element_to_dlist(dlist_t *dlist, void *data);
char add_element_to_end_dlist(dlist_t *dlist, void *data);
dlist_t *create_dlist(void);
dlist_t *clone_dlist(dlist_t *ori, char inverse);
void delete_node_from_dlist(dlist_t *node);
void delete_data_from_dlist(dlist_t *root, void *data);
void my_rev_dlist(dlist_t *dlist);

#endif /* !MY_DLIST_H_ */