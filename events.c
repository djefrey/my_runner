/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** events
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "my_list.h"
#include "my_runner.h"

static void manage_mouse(sfMouseButtonEvent mouseEv, infos_t *infos)
{

}

static void manage_keyboard(sfKeyEvent keyEv, infos_t *infos)
{
    if (keyEv.type == sfEvtKeyPressed) {
        if (keyEv.code == sfKeySpace && ABS(infos->player->acceleration.y) < 0.01)
            infos->player->acceleration.y -= 20;
    }
}

void analyse_events(sfRenderWindow *window, infos_t *infos)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            continue;
        }
        manage_keyboard(event.key, infos);
        manage_mouse(event.mouseButton, infos);
    }
}