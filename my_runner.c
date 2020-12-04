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

void update_block(object_t *obj, list_t *objs, unsigned int elapsed)
{
    set_position(obj, obj->pos.x - SCROLLING_SPEED, obj->pos.y);
}

static void update(infos_t *infos, unsigned int elapsed, unsigned int *bkgdpos)
{
    list_t *list = infos->objects;
    object_t *obj = NULL;

    *bkgdpos += SCROLLING_SPEED;
    move_backgrounds(infos, *bkgdpos);
    while (list) {
        obj = (object_t*) list->data;
        (*(obj->update))(obj, infos->objects, elapsed);
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
    unsigned int bkgdpos = 0;
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(window)) {
        elapsed = sfClock_restart(clock).microseconds / FPS;
        analyse_events(window, infos);
        update(infos, elapsed, &bkgdpos);
        draw(window, infos);
    }
    sfClock_destroy(clock);
}

int game(sfRenderWindow *window)
{
    infos_t *infos = create_infos();
    object_t *obj;

    if (!infos)
        return (84);
    for (int i = 0; i < 15; i++) {
        obj = create_object(infos, BLOCK, BLOCK_TEXT, &update_block);
        set_position(obj, (i + 50) * 64, WINDOW_HEIGHT - GROUND_HEIGHT - BLOCK_SIZE);
    }
    loop(window, infos);
    destroy_infos(infos);
    return (0);
}