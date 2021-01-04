/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** game draw
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include "my_list.h"
#include "my_runner.h"

void game_draw(sfRenderWindow *window, infos_t *infos)
{
    object_t *obj;

    for (list_t *list = infos->backgrounds; list; list = list->next)
        sfRenderWindow_drawSprite(window, (sfSprite*) list->data, NULL);
    for (list_t *list = infos->objects; list; list = list->next) {
        obj = ((object_t*) list->data);
        if (!obj->hide && obj->pos.x < WINDOW_WIDTH + BLOCK_SIZE)
            sfRenderWindow_drawSprite(window, obj->sprite, NULL);
    }
    sfRenderWindow_drawText(window, infos->score->text, NULL);
    if (infos->status == PAUSE) {
        sfRenderWindow_drawSprite(window, infos->fade->sprite, NULL);
        sfRenderWindow_drawText(window, infos->texts->title, NULL);
        sfRenderWindow_drawText(window, infos->texts->infos, NULL);
    }
}

void end_draw(sfRenderWindow *window, infos_t *infos)
{
    object_t *obj;

    for (list_t *list = infos->backgrounds; list; list = list->next)
        sfRenderWindow_drawSprite(window, (sfSprite*) list->data, NULL);
    for (list_t *list = infos->objects; list; list = list->next) {
        obj = ((object_t*) list->data);
        if (obj->type == PLAYER)
            continue;
        if (!obj->hide && obj->pos.x < WINDOW_WIDTH + BLOCK_SIZE)
            sfRenderWindow_drawSprite(window, obj->sprite, NULL);
    }
    sfRenderWindow_drawSprite(window, infos->fade->sprite, NULL);
    sfRenderWindow_drawSprite(window, infos->player->sprite, NULL);
}

void victory_draw(sfRenderWindow *window, infos_t *infos)
{
    sfRenderWindow_drawSprite(window, infos->player->sprite, NULL);
    sfRenderWindow_drawText(window, infos->texts->title, NULL);
    sfRenderWindow_drawText(window, infos->texts->infos, NULL);
}