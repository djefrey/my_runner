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
    free(infos);
    return (NULL);
}

infos_t *create_infos(void)
{
    infos_t *infos = malloc(sizeof(infos_t));

    if (infos == NULL)
        return (NULL);
    infos->textures = load_textures();
    if (!(infos->textures))
        return (destroy_infos(infos));
    infos->backgrounds = create_backgrounds(infos);
    if (!(infos->backgrounds))
        return (destroy_infos(infos));
    infos->player = create_player(infos);
    if (!(infos->player))
        return (destroy_infos(infos));
    infos->objects = NULL;
    create_list(&(infos->objects), infos->player);
    if (!(infos->objects)) {
        destroy_object(infos->player);
        return (destroy_infos(infos));
    }
    return (infos);
}