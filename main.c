/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** main
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "my_runner.h"

static sfRenderWindow *create_window(int ac, char *av[])
{
    int width = ac == 4 ? my_getnbr(av[2]) : WINDOW_WIDTH;
    int height = ac == 4 ? my_getnbr(av[3]) : WINDOW_HEIGHT;
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window =
    sfRenderWindow_create(mode, WINDOW_TITLE, sfDefaultStyle, NULL);
    sfView *view = sfView_create();
    sfVector2f view_size = {WINDOW_WIDTH, WINDOW_HEIGHT};
    sfVector2f view_center = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};

    sfView_setSize(view, view_size);
    sfView_setCenter(view, view_center);
    sfRenderWindow_setView(window, view);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

int main(int ac, char *av[])
{
    sfRenderWindow *window = create_window(ac, av);
    char *level;

    if (ac == 1) {
        sfRenderWindow_destroy(window);
        return (84);
    }
    level = av[1];
    return (game(window, level));
}