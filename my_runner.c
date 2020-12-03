/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** main file
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "my_list.h"
#include "my_runner.h"

static void update(infos_t *infos, unsigned int elapsed, unsigned int *pos)
{
    list_t *list = infos->objects;
    object_t *obj = NULL;

    *pos += 10;
    move_backgrounds(infos, *pos);
    while (list) {
        obj = (object_t*) list->data;
        (*(obj->update))(obj, elapsed, *pos);
        list = list->next;
    }
}

static void draw(sfRenderWindow *window, infos_t *infos)
{
    list_t *list = infos->backgrounds;

    sfRenderWindow_clear(window, sfBlack);
    while (list) {
        sfRenderWindow_drawSprite(window, (sfSprite*) list->data, NULL);
        list = list->next;
    }
    list = infos->objects;
    while (list) {
        sfRenderWindow_drawSprite(window,
        ((object_t*) list->data)->sprite, NULL);
        list = list->next;
    }
    sfRenderWindow_display(window);
}

static void loop(sfRenderWindow *window, infos_t *infos)
{
    unsigned int elapsed = 0;
    unsigned int pos = 1;
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(window)) {
        elapsed = sfClock_restart(clock).microseconds;
        analyse_events(window, infos);
        update(infos, elapsed, &pos);
        draw(window, infos);
    }
    sfClock_destroy(clock);
}

int game(sfRenderWindow *window)
{
    infos_t *infos = create_infos();

    if (!infos)
        return (84);
    loop(window, infos);
    destroy_infos(infos);
    return (0);
}