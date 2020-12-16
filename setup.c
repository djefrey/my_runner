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

void *destroy_infos(infos_t *infos)
{
    destroy_textures(infos->textures);
    destroy_backgrounds(infos->backgrounds);
    destroy_objects(infos->objects);
    score_display_destroy(infos->score_display);
    free(infos);
    return (NULL);
}

infos_t *create_infos(void)
{
    infos_t *infos = malloc(sizeof(infos_t));

    if (infos == NULL)
        return (NULL);
    infos->score = 0;
    infos->objects = NULL;
    if (!(infos->textures = load_textures()) ||
    !(infos->backgrounds = create_backgrounds(infos)) ||
    !(infos->player = create_player(infos)) ||
    !(infos->score_display = score_display_create()))
        return (destroy_infos(infos));
    return (infos);
}