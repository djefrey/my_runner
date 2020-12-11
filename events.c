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

static void manage_mouse(sfMouseButtonEvent mouseEv,
infos_t *infos,unsigned int elapsed)
{

}

static void manage_keyboard(sfKeyEvent keyEv,
infos_t *infos, unsigned int elapsed)
{
    if (keyEv.type == sfEvtKeyPressed) {
        if (keyEv.code == sfKeySpace && infos->player->acc.y == 0)
            infos->player->acc.y -= 20 * elapsed;
    }
}

void analyse_events(sfRenderWindow *window,
infos_t *infos, unsigned int elapsed)
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