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

static void set_skin_texture(skin_t *skin, sfSprite *sprite)
{
    sfTexture *texture = skin->texture;

    sfSprite_setTexture(sprite, texture, 0);
}

static void manage_keyboard(sfKeyEvent keyEv, char *start_game,
dlist_t **skin, sfSprite *sprite)
{
    if (keyEv.type == sfEvtKeyPressed) {
        switch (keyEv.code) {
            case sfKeySpace:
                *start_game = 1;
                break;
            case sfKeyLeft:
                *skin = (*skin)->prev;
                if ((*skin)->data == NULL)
                    *skin = (*skin)->prev;
                set_skin_texture((skin_t*) (*skin)->data, sprite);
                break;
            case sfKeyRight:
                *skin = (*skin)->next;
                if ((*skin)->data == NULL)
                    *skin = (*skin)->next;
                set_skin_texture((skin_t*) (*skin)->data, sprite);
                break;
            default:
                break;
        }
    }
}

void menu_events(sfRenderWindow *window, char *start_game,
dlist_t **skin, sfSprite *sprite)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            continue;
        }
        manage_keyboard(event.key, start_game, skin, sprite);
    }
}