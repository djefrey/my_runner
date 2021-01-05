/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** skins loader
*/

#include <stdlib.h>
#include "my_dlist.h"
#include "menu.h"
#include "skins_list.h"

void destroy_skins(dlist_t *root)
{
    dlist_t *list = root->next;
    dlist_t *tmp;
    skin_t *skin;

    while (list != root) {
        tmp = list->next;
        skin = (skin_t*) list->data;
        sfTexture_destroy(skin->texture);
        free(skin);
        free(list);
        list = tmp;
    }
    free(root);
}

dlist_t *load_skins(void)
{
    dlist_t *root = create_dlist();
    skin_t *skin;
    const char *path;

    for (int i = 0; i < SKINS_NB; i++) {
        skin = malloc(sizeof(skin_t));
        path = SKINS_LIST[i];
        skin->path = path;
        skin->texture = sfTexture_createFromFile(path, NULL);
        if (!skin->texture) {
            destroy_skins(root);
            return (NULL);
        }
        add_element_to_end_dlist(root, skin);
    }
    return (root);
}