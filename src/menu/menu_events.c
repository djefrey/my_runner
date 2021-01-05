/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** menu events
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "menu.h"
#include "my_dlist.h"

static void manage_keyboard(sfKeyEvent keyEv, char *start_game,
int *sprite_id, sfSprite *sprite)
{
    if (keyEv.type == sfEvtKeyPressed) {
        switch (keyEv.code) {
            case sfKeySpace:
                *start_game = 1;
                break;
            case sfKeyLeft:
                *sprite_id = *sprite_id == 0 ? 3 : *sprite_id - 1;
                break;
            case sfKeyRight:
                *sprite_id = *sprite_id == 3 ? 0 : *sprite_id + 1;
                break;
            default:
                break;
        }
        sfSprite_setTextureRect(sprite,
        (sfIntRect) {64 * *sprite_id, 0, 64, 64});
    }
}

void menu_events(sfRenderWindow *window, char *start_game,
int *sprite_id, sfSprite *sprite)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            continue;
        }
        manage_keyboard(event.key, start_game, sprite_id, sprite);
    }
}