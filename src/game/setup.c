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
    free(infos);
}

infos_t *create_infos(char *player_skin)
{
    infos_t *infos = malloc(sizeof(infos_t));

    if (infos == NULL)
        return (NULL);
    infos->score = 0;
    infos->objects = NULL;
    if (!(infos->textures = load_textures(player_skin)) ||
    !(infos->backgrounds = create_backgrounds(infos)) ||
    !(infos->player = create_player(infos)) ||
    !(infos->score = create_score()) ||
    !(infos->fade = create_fade(sfColor_fromRGBA(0, 0, 0, 0))) ||
    !(infos->texts = create_texts())) {
        destroy_infos(infos);
        return (NULL);
    }
    return (infos);
}