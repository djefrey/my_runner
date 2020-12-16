/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** physics
*/

#include "my_runner.h"

char check_collision(object_t* p_obj, object_t *obj)
{
    int p_posx = p_obj->pos.x + p_obj->acc.x;
    int p_top = p_obj->pos.y + p_obj->acc.y;
    int p_bot = p_top + BLOCK_SIZE;
    int o_posx = obj->pos.x;
    int o_top = obj->pos.y;
    int o_bot = o_top + BLOCK_SIZE;

    if (obj->hide)
        return (0);
    if ((p_posx >= o_posx && p_posx <= o_posx + BLOCK_SIZE) || (p_posx
    + BLOCK_SIZE >= o_posx && p_posx + BLOCK_SIZE <= o_posx + BLOCK_SIZE)) {
        if (p_obj->acc.y >= 0 && ABS(p_bot - o_top) <= 32)
            return (2);
        else if (p_obj->acc.y < 0 && ABS(o_bot - p_top) <= 32)
            return (3);
        else
            return ((p_top <= o_top && p_bot >= o_top) ||
            (p_top >= o_top && p_top <= o_bot));
    }
    return (0);
}