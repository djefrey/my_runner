/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** pistons
*/

#include <SFML/Graphics.h>
#include "my_runner.h"

void extend_piston(object_t *base, infos_t *infos)
{
    object_t *head = create_object(infos, BLOCK,
    PISTON_TEXT, &update_piston_head);

    set_position(head, base->pos.x, base->pos.y - 64);
    sfSprite_setTextureRect(base->sprite, (sfIntRect) {64, 0, 64, 64});
    sfSprite_setTextureRect(head->sprite, (sfIntRect) {128, 0, 64, 64});
    base->time = 20;
    head->time = 20;
}

void update_piston_head(object_t *obj, void *infos_void, float elapsed)
{
    infos_t *infos = (infos_t*) infos_void;

    update_block(obj, infos_void, elapsed);
    obj->time -= 1;
    if (obj->time <= 0) {
        destroy_object(obj, &(infos->objects));
    }
}

void update_piston_base(object_t *obj, void *infos_void, float elapsed)
{
    update_block(obj, infos_void, elapsed);
    if (sfSprite_getTextureRect(obj->sprite).left == 64) {
        obj->time -= 1;
        if (obj->time <= 0)
            sfSprite_setTextureRect(obj->sprite, (sfIntRect) {0, 0, 64, 64});
    }
}