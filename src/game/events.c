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
    } else {
        infos->status = GAME;
        infos->fade->alpha = 0;
    }
    update_fade_sprite(infos->fade);
}

static void manage_mouse(sfMouseButtonEvent mouseEv,
infos_t *infos, float elapsed)
{

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
        manage_mouse(event.mouseButton, infos, elapsed);
    }
}