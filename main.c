/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** main
*/

#include <SFML/Graphics.h>
#include "my_runner.h"

static sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    sfRenderWindow *window =
    sfRenderWindow_create(mode, WINDOW_TITLE, sfTitlebar | sfClose, NULL);

    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

int main(int ac, char *av[])
{
    sfRenderWindow *window = create_window();
    int ret = game(window, "./bonus/level.txt");

    sfRenderWindow_destroy(window);
    return (ret);
}