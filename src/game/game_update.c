/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** game update
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include "my.h"
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
        play_sound(infos->audio, DAMAGE_SOUND);
    }
    set_score(infos->score);
}

static void set_ask_name_status(infos_t *infos, float elapsed)
{
    float rot = infos->player->rot;

    if (infos->fade->alpha == 255) {
        if (rot <= (3 * elapsed) || rot >= (360 - 3 * elapsed)) {
            set_rotation((object_t*) infos->player, 0);
            infos->status = ASK_NAME;
        }
    }
}

void end_update(infos_t *infos, float elapsed)
{
    object_t *player = (object_t*) infos->player;

    increase_fade_alpha(infos->fade, (int) ceil(elapsed));
    update_fade_sprite(infos->fade);
    set_position(player, 896, 476);
    set_rotation(player, player->rot + 5 * elapsed);
    set_texts(infos->texts, "Entrez votre nom", "");
    set_ask_name_status(infos, elapsed);
}

static void set_victory_text(infos_t *infos)
{
    char score_str[13] = {0};
    list_t *list = infos->leaderboard->list;
    char *str;
    char *tmp;

    get_score_str(score_str, infos->score->score);
    str = my_strmerge(score_str, "\n\nLeaderboard:\n");
    for (int i = 0; i < 5 && list; i++, list = list->next) {
        tmp = my_strmerge(str, (char*) list->data);
        free(str);
        str = my_strmerge(tmp, "\n");
        free(tmp);
    }
    set_texts(infos->texts, "VICTOIRE", str);
    free(str);
}

void victory_update(infos_t *infos)
{
    const char *name = sfText_getString(infos->texts->infos);

    add_entry_to_leaderboard(infos->leaderboard, name, infos->score->score);
    write_leaderboard_file(infos->leaderboard);
    set_victory_text(infos);
    infos->quit_button->hide = 0;
    infos->status = END;
}