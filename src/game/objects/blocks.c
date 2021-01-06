/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** blocks
*/

#include "my_runner.h"

void update_block(object_t *obj, void *infos, float elapsed)
{
    set_position(obj, obj->pos.x - SCROLLING_SPEED * elapsed, obj->pos.y);
    if (obj->pos.x <= -BLOCK_SIZE)
        obj->hide = 1;
}

void update_emerald(object_t *obj, void *infos, float elapsed)
{
    int x = sfSprite_getTextureRect(obj->sprite).left;

    update_block(obj, infos, elapsed);
    obj->time += elapsed;
    if (obj->time >= 60) {
        sfSprite_setTextureRect(obj->sprite, (sfIntRect) {0, 0, 64, 64});
        obj->time = 0;
    } else if (obj->time >= 40) {
        if (obj->time >= 50 && x == 64) {
            sfSprite_setTextureRect(obj->sprite, (sfIntRect) {128, 0, 64, 64});
        } else if (x == 0)
            sfSprite_setTextureRect(obj->sprite, (sfIntRect) {64, 0, 64, 64});
    }
}

void update_fire(object_t *obj, void *infos, float elapsed)
{
    int x;

    update_block(obj, infos, elapsed);
    obj->time += elapsed;
    if (obj->time >= 4) {
        x = sfSprite_getTextureRect(obj->sprite).left;
        x = x == 128 ? 0 : x + 64;
        sfSprite_setTextureRect(obj->sprite, (sfIntRect) {x, 0, 64, 64});
        obj->time = 0;
    }
}

void reset_blocks(list_t *list)
{
    object_t *obj;

    for (; list != NULL; list = list->next) {
        obj = (object_t*) list->data;
        if (obj->type == PLAYER)
            continue;
        set_position(obj, obj->ori_x, obj->pos.y);
        obj->hide = 0;
    }
}