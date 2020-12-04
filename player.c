/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** player
*/

#include <SFML/Graphics.h>
#include "my_runner.h"

static char check_collision(object_t* p_obj, object_t *obj)
{
    int p_posx = p_obj->pos.x;
    int p_top = p_obj->pos.y;
    int o_posx = obj->pos.x;
    int o_top = obj->pos.y;

    if ((p_posx >= o_posx && p_posx <= o_posx + BLOCK_SIZE) || (p_posx
    + BLOCK_SIZE >= o_posx&& p_posx + BLOCK_SIZE <= o_posx + BLOCK_SIZE)) {
        if (p_obj->acceleration.y > 0 && ABS((p_top + BLOCK_SIZE - o_top)) < 12)
            return (2);
        else if(p_top + BLOCK_SIZE <= o_top || p_top >= o_top + BLOCK_SIZE)
            return (0);
        else
            return (1);
    } else
        return (0);
}

void update_player(object_t *obj, list_t *objs, unsigned int elapsed)
{
    char result;
    object_t *block;

    if (obj->pos.y + BLOCK_SIZE < WINDOW_HEIGHT - GROUND_HEIGHT)
        obj->acceleration.y += elapsed;
    else if(obj->acceleration.y > 0)
        obj->acceleration.y = 0;
    for (; objs; objs = objs->next) {
        block = (object_t*) objs->data;
        if (block->type == PLAYER)
            continue;
        result = check_collision(obj, block);
        if (result == 2)
            obj->acceleration.y = 0;
        else if(result == 1)
            printf("ooof\n");
    }
    set_position(obj, obj->pos.x, obj->pos.y + obj->acceleration.y);
}

object_t *create_player(infos_t *infos)
{
    object_t *obj = create_object(infos, PLAYER, PLAYER_TEXT, &update_player);

    set_position(obj, PLAYER_POS, 10);
    return (obj);
}