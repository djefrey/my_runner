/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** player
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "my_runner.h"

static void set_player_on_ground(object_t *obj)
{
    obj->acc.y = 0;
    obj->pos.y = (int) (round(obj->pos.y / 64.0)) * 64;
}

static void detect_collision(object_t *obj, list_t **objs)
{
    char result;
    object_t *block;

    for (list_t *list = *objs; list; list = list->next) {
        block = (object_t*) list->data;
        if (block->type == PLAYER)
            continue;
        result = check_collision(obj, block);
        switch (result) {
            case 1:
                destroy_object(obj, objs);
                break;
            case 2:
                if (block->type == BLOCK)
                    set_player_on_ground(obj);
                else if (block->type == SPIKE)
                    destroy_object(obj, objs);
                break;
            case 3:
                obj->acc.y = 0;
                break;
        }
    }
}

void update_player(object_t *obj, list_t **objs, unsigned int elapsed)
{
    if (obj->pos.y + BLOCK_SIZE < WINDOW_HEIGHT - GROUND_HEIGHT)
        obj->acc.y += GRAVITY * elapsed;
    if(obj->acc.y > 0 && obj->pos.y + BLOCK_SIZE >= WINDOW_HEIGHT - GROUND_HEIGHT)
        set_player_on_ground(obj);
    detect_collision(obj, objs);
    set_position(obj, obj->pos.x, obj->pos.y + obj->acc.y);
}

object_t *create_player(infos_t *infos)
{
    object_t *obj = create_object(infos, PLAYER, PLAYER_TEXT, &update_player);

    set_position(obj, PLAYER_POS, GROUND_HEIGHT - BLOCK_SIZE);
    return (obj);
}