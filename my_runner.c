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

static void update(infos_t *infos, float elapsed, float *pos)
{
    if (infos->status == GAME)
        game_update(infos, elapsed, pos);
    if (infos->status == END_ANIM)
        end_update(infos, elapsed);
}

static void draw(sfRenderWindow *window, infos_t *infos)
{
    sfRenderWindow_clear(window, sfBlack);

    if (infos->status == VICTORY) {
        printf("slt\n");
    } else if (infos->status == END_ANIM)
        end_draw(window, infos);
    else
        game_draw(window, infos);
    sfRenderWindow_display(window);
}

static void loop(sfRenderWindow *window, infos_t *infos)
{
    float elapsed = 0;
    float pos = 0;
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(window)) {
        elapsed = sfClock_restart(clock).microseconds / FPS;
        analyse_events(window, infos, elapsed);
        update(infos, elapsed, &pos);
        draw(window, infos);
    }
    sfClock_destroy(clock);
}

int game(sfRenderWindow *window, char *level)
{
    infos_t *infos = create_infos();
    int level_size;

    if (!infos || (level_size = load_level(level, infos)) == -1)
        return (84);
    infos->status = GAME;
    infos->level_size = level_size - LEVEL_END;
    loop(window, infos);
    destroy_infos(infos);
    return (0);
}