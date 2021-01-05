/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** events
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <math.h>
#include "my_list.h"
#include "my_runner.h"

static void set_pause(infos_t *infos)
{
    if (infos->status == GAME) {
        infos->status = PAUSE;
        infos->fade->alpha = 127;
        sfMusic_pause(infos->audio->music);
    } else {
        infos->status = GAME;
        infos->fade->alpha = 0;
        sfMusic_play(infos->audio->music);
    }
    update_fade_sprite(infos->fade);
}

static void manage_keyboard(sfKeyEvent keyEv,
infos_t *infos, float elapsed)
{
    player_t *player = infos->player;

    if (infos->status > PAUSE)
        return;
    if (keyEv.type == sfEvtKeyPressed) {
        if (keyEv.code == sfKeyEscape)
            set_pause(infos);
        if (keyEv.code == sfKeySpace && player->on_ground
        && infos->status == GAME) {
            player->acc.y -= 20 * sqrt(elapsed);
            player->on_ground = 0;
        }
    }
}

void analyse_events(sfRenderWindow *window,
infos_t *infos, float elapsed)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            continue;
        }
        manage_keyboard(event.key, infos, elapsed);
    }
}