/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <unistd.h>
#include "my.h"
#include "my_runner.h"

static sfRenderWindow *create_window(int ac, char *av[])
{
    int width = ac >= 4 ? my_getnbr(av[2]) : WINDOW_WIDTH;
    int height = ac >= 4 ? my_getnbr(av[3]) : WINDOW_HEIGHT;
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window =
    sfRenderWindow_create(mode, WINDOW_TITLE, sfDefaultStyle, NULL);
    sfView *view = sfView_create();
    sfVector2f view_size = {WINDOW_WIDTH, WINDOW_HEIGHT};
    sfVector2f view_center = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};

    sfView_setSize(view, view_size);
    sfView_setCenter(view, view_center);
    sfRenderWindow_setView(window, view);
    sfRenderWindow_setFramerateLimit(window, ac >= 5 ? my_getnbr(av[4]) : 60);
    return (window);
}

static void print_help(void)
{
    my_putstr("MY_RUNNER\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     Jump at the right moment to dodge obstacles\n");
    my_putstr("\nCONTROLS\n");
    my_putstr("     space: start (menu) / jump (game)\n");
    my_putstr("     esc: pause (game)\n");
    my_putstr("     left/right: select skin (menu)\n");
    my_putstr("\nARGUMENTS\n");
    my_putstr("     ./my_runner level_file.txt [width] [height] [fps]\n");
}

int main(int ac, char *av[])
{
    sfRenderWindow *window;
    char *level;
    int len;

    if (ac == 1) {
        write(2, "Level file not provided\n", 24);
        return (84);
    }
    if (my_strcmp(av[1], "-h") == 0) {
        print_help();
        return (0);
    }
    len = my_strlen(av[1]);
    if (len < 4 || my_strcmp(av[1] + len - 4, ".txt")) {
        write(2, "Level format not supported\n", 27);
        return (84);
    }
    window = create_window(ac, av);
    level = av[1];
    return (menu(window, level));
}