/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** menu
*/

#include <SFML/Graphics.h>
#include "my_hunter.h"

static void menu_events(sfRenderWindow *window, char *start_game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            continue;
        }
        if (event.mouseButton.type == sfEvtMouseButtonPressed)
            *start_game = 1;
    }
}

int menu(sfRenderWindow *window)
{
    char start_game = 0;
    sfTexture *bkgd_text;
    sfSprite *bkgd;

    bkgd_text = sfTexture_createFromFile("./assets/sprites/menu.png", NULL);
    bkgd = sfSprite_create();
    sfSprite_setTexture(bkgd, bkgd_text, sfFalse);
    while (sfRenderWindow_isOpen(window) && !start_game) {
        menu_events(window, &start_game);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, bkgd, NULL);
        sfRenderWindow_display(window);
    }
    sfTexture_destroy(bkgd_text);
    sfSprite_destroy(bkgd);
    if (start_game)
        return (game(window));
    else
        return (0);
}