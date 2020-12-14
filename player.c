/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** player
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "my_runner.h"

static void set_player_on_ground(object_t *obj, int ground_y)
{
    obj->acc.y = 0;
    obj->pos.y = ground_y - 64;
    if ((int) round(obj->rot) % 90 != 0)
        set_rotation(obj, round(obj->rot / 90.0) * 90);
}

static void detect_collision(object_t *obj, object_t *block)
{
    char result = check_collision(obj, block);

    switch (result) {
        case 1:
            obj->dead = 1;
            break;
        case 2:
            if (block->type == BLOCK)
                set_player_on_ground(obj, block->pos.y);
            else if (block->type == SPIKE)
                obj->dead = 1;
            break;
        case 3:
            obj->acc.y = 0;
            break;
    }
}

void update_player(object_t *obj, list_t **objs, unsigned int elapsed)
{
    object_t *block;

    if (obj->pos.y + BLOCK_SIZE < GROUND_HEIGHT)
        obj->acc.y += GRAVITY * elapsed;
    if(obj->acc.y > 0 && obj->pos.y + BLOCK_SIZE >= GROUND_HEIGHT)
        set_player_on_ground(obj, GROUND_HEIGHT);
    for (list_t *list = *objs;  list != NULL; list = list->next) {
        block = (object_t*) list->data;
        if (block->type == PLAYER)
            continue;
        detect_collision(obj, block);
    }
    set_position(obj, obj->pos.x, obj->pos.y + obj->acc.y);
    if (obj->acc.y != 0)
        set_rotation(obj, obj->rot + 11.25 * elapsed);
}

void reset_player(object_t *obj)
{
    set_position(obj, PLAYER_POS, GROUND_HEIGHT - BLOCK_SIZE);
    set_rotation(obj, 0);
}

object_t *create_player(infos_t *infos)
{
    object_t *obj = create_object(infos, PLAYER, PLAYER_TEXT, &update_player);

    reset_player(obj);
    return (obj);
}