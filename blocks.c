/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** blocks
*/

#include "my_runner.h"

void update_block(object_t *obj, void *infos, unsigned int elapsed)
{
    set_position(obj, obj->pos.x - SCROLLING_SPEED * elapsed, obj->pos.y);
    if (obj->pos.x <= -BLOCK_SIZE)
        obj->hide = 1;
}

void reset_blocks(list_t *list, unsigned int pos)
{
    object_t *obj;

    for (; list != NULL; list = list->next) {
        obj = (object_t*) list->data;
        if (obj->type == PLAYER)
            continue;
        set_position(obj, obj->pos.x + pos, obj->pos.y);
        obj->hide = 0;
    }
}