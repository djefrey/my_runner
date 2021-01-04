/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** game update
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "my_list.h"
#include "my_runner.h"

void end_update(infos_t *infos, float elapsed)
{
    object_t *player = infos->player;

    set_position(player, 960, 540);
    set_rotation(player, player->rot + 10);
}

void game_update(infos_t *infos, float elapsed, float *pos)
{
    object_t *obj = NULL;

    *pos += SCROLLING_SPEED * elapsed;
    if (*pos >= infos->level_size) {
        infos->status = END_ANIM;
        return;
    }
    move_backgrounds(infos, *pos);
    for (list_t *list = infos->objects; list; list = list->next) {
        obj = (object_t*) list->data;
        (*(obj->update))(obj, infos, elapsed);
    }
    if (infos->player->dead) {
        reset_blocks(infos->objects, *pos);
        reset_player(infos->player);
        infos->score->score = 0;
        *pos = 0;
    }
    set_score(infos->score);
}