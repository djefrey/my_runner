/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** game update
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include "my_list.h"
#include "my_runner.h"

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
        reset_blocks(infos->objects);
        reset_player(infos->player);
        infos->score->score = 0;
        *pos = 0;
    }
    set_score(infos->score);
}

static void set_victory_status(infos_t *infos, float elapsed)
{
    float rot = infos->player->rot;

    if (infos->fade->alpha == 255) {
        if (rot <= (3 * elapsed) || rot >= (360 - 3 * elapsed)) {
            set_rotation((object_t*) infos->player, 0);
            set_texts(infos->texts, "VICTOIRE", "Y'aura ton score ici");
            infos->status = VICTORY;
        }
    }
}

void end_update(infos_t *infos, float elapsed)
{
    object_t *player = (object_t*) infos->player;

    increase_fade_alpha(infos->fade, (int) ceil(elapsed));
    update_fade_sprite(infos->fade);
    set_position(player, 930, 510);
    set_rotation(player, player->rot + 5 * elapsed);
    set_victory_status(infos, elapsed);
}