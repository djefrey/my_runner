/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** events
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <math.h>
#include "my.h"
#include "my_list.h"
#include "my_runner.h"

static void set_pause(infos_t *infos)
{
    if (infos->status == GAME) {
        infos->status = PAUSE;
        infos->fade->alpha = 127;
        sfMusic_pause(infos->audio->music);
    } else {
        infos->status = GAME;
        infos->fade->alpha = 0;
        sfMusic_play(infos->audio->music);
    }
    update_fade_sprite(infos->fade);
}

static void manage_text(sfTextEvent textEv, infos_t *infos)
{
    char c;
    char letter[2] = {0};
    const char *str;
    char *tmp;

    if (infos->status == ASK_NAME) {
        c = (char) textEv.unicode;
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            letter[0] = c;
            str = sfText_getString(infos->texts->infos);
            tmp = my_strmerge(str, letter);
            sfText_setString(infos->texts->infos, tmp);
            free(tmp);
        }
    }
}

static void backspace_text(sfText *text)
{
    char *str = sfText_getString(text);
    int len = my_strlen(str);

    if (len == 0)
        return;
    str[len - 1] = 0;
    sfText_setString(text, str);
}

static void manage_keyboard(sfKeyEvent keyEv,
infos_t *infos, float elapsed)
{
    player_t *player = infos->player;

    if (keyEv.type == sfEvtKeyPressed) {
        if (infos->status == GAME || infos->status == PAUSE) {
            if (keyEv.code == sfKeyEscape)
                set_pause(infos);
            if (keyEv.code == sfKeySpace && player->on_ground
            && infos->status == GAME) {
                player->acc.y -= 20 * elapsed;
                player->on_ground = 0;
            }
        } else if (infos->status == ASK_NAME) {
            if (keyEv.code == sfKeyEnter)
                infos->status = VICTORY;
            else if (keyEv.code == sfKeyBackspace)
                backspace_text(infos->texts->infos);
        }
    }
}

void analyse_events(sfRenderWindow *window,
infos_t *infos, float elapsed)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            continue;
        }
        manage_keyboard(event.key, infos, elapsed);
        manage_text(event.text, infos);
    }
}