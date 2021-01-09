/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** setup
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_list.h"
#include "my_runner.h"

void destroy_infos(infos_t *infos)
{
    destroy_textures(infos->textures);
    destroy_backgrounds(infos->backgrounds);
    destroy_objects(infos->objects);
    destroy_score(infos->score);
    destroy_fade(infos->fade);
    destroy_texts(infos->texts);
    destroy_audio(infos->audio);
    destroy_leaderboard(infos->leaderboard);
    destroy_button(infos->quit_button);
    free(infos);
}

static infos_t *create_null_infos(void)
{
    infos_t *infos = malloc(sizeof(infos_t));

    if (!infos)
        return (NULL);
    infos->score = 0;
    infos->objects = NULL;
    infos->textures = NULL;
    infos->backgrounds = NULL;
    infos->player = NULL;
    infos->score = NULL;
    infos->fade = NULL;
    infos->texts = NULL;
    infos->audio = NULL;
    infos->leaderboard = NULL;
    infos->quit_button = NULL;
    return (infos);
}

infos_t *create_infos(char *level)
{
    infos_t *infos = create_null_infos();

    if (infos == NULL)
        return (NULL);
    if (!(infos->textures = load_textures()) ||
    !(infos->backgrounds = create_backgrounds(infos)) ||
    !(infos->player = create_player(infos)) ||
    !(infos->score = create_score()) ||
    !(infos->fade = create_fade(sfColor_fromRGBA(0, 0, 0, 0))) ||
    !(infos->texts = create_texts()) ||
    !(infos->audio = create_audio(level)) ||
    !(infos->leaderboard = load_leaderboard(level)) ||
    !(infos->quit_button = create_button("Quitter",
    (sfVector2f) {30, 1010}, &quit_fct, infos->texts->font))) {
        destroy_infos(infos);
        return (NULL);
    }
    return (infos);
}