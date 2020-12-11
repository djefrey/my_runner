/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** player
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "my_runner.h"

static char check_collision(object_t* p_obj, object_t *obj)
{
    int p_posx = p_obj->pos.x;
    int p_top = p_obj->pos.y;
    int o_posx = obj->pos.x;
    int o_top = obj->pos.y;

    if ((p_posx >= o_posx && p_posx <= o_posx + BLOCK_SIZE) || (p_posx
    + BLOCK_SIZE >= o_posx&& p_posx + BLOCK_SIZE <= o_posx + BLOCK_SIZE)) {
        if (p_obj->acc.y > 0 && ABS((p_top + BLOCK_SIZE - o_top)) < 8)
            return (2);
        else if (p_top + BLOCK_SIZE <= o_top || p_top >= o_top + BLOCK_SIZE)
            return (0);
        else
            return (1);
    } else
        return (0);
}

static void set_player_on_ground(object_t *obj)
{
    obj->acc.y = 0;
    obj->pos.y = (int) (round(obj->pos.y / 64.0)) * 64;
}

void update_player(object_t *obj, list_t **objs, unsigned int elapsed)
{
    char result;
    object_t *block;

    if (obj->pos.y + BLOCK_SIZE < WINDOW_HEIGHT - GROUND_HEIGHT)
        obj->acc.y += GRAVITY * elapsed;
    if(obj->acc.y > 0 && obj->pos.y + BLOCK_SIZE >= WINDOW_HEIGHT - GROUND_HEIGHT)
        set_player_on_ground(obj);
    for (list_t *list = *objs; list; list = list->next) {
        block = (object_t*) list->data;
        if (block->type == PLAYER)
            continue;
        result = check_collision(obj, block);
        if (result == 2) {
            if (block->type == BLOCK)
                set_player_on_ground(obj);
            else if (block->type == SPIKE)
                destroy_object(obj, objs);
        } else if(result == 1)
            destroy_object(obj, objs);
    }
    set_position(obj, obj->pos.x, obj->pos.y + obj->acc.y);
}

object_t *create_player(infos_t *infos)
{
    object_t *obj = create_object(infos, PLAYER, PLAYER_TEXT, &update_player);

    set_position(obj, PLAYER_POS, 10);
    return (obj);
}