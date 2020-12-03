/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** player
*/

#include <SFML/Graphics.h>
#include "my_runner.h"

void update_player(object_t *obj, unsigned int elapsed, unsigned int pos)
{

}

object_t *create_player(infos_t *infos)
{
    object_t *obj = create_object(infos, PLAYER, PLAYER_TEXT, &update_player);
    sfVector2f scale = {5, 5};
    sfVector2f pos = {PLAYER_POS, 50};

    sfSprite_setScale(obj->sprite, scale);
    sfSprite_setPosition(obj->sprite, pos);
    return (obj);
}