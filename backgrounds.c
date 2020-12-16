/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** backgrounds
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include "my_list.h"
#include "my_runner.h"

void move_backgrounds(infos_t *infos, unsigned int pos)
{
    list_t *backgrounds = infos->backgrounds;
    int offset;
    sfIntRect bkgd_pos = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    for (int i = 1; i < 4; i++, backgrounds = backgrounds->next) {
        offset = ((int) ceil(pos * (1.0 / (12 - i * 3)))) % WINDOW_WIDTH;
        bkgd_pos.left = offset;
        bkgd_pos.width = WINDOW_WIDTH + offset;
        sfSprite_setTextureRect((sfSprite*) backgrounds->data, bkgd_pos);
    }
}

void destroy_backgrounds(list_t *backgrounds)
{
    list_t *tmp;

    while (backgrounds) {
        tmp = backgrounds->next;
        if (backgrounds->data)
            sfSprite_destroy(backgrounds->data);
        free(backgrounds);
        backgrounds = tmp;
    }
}

static sfSprite *create_background(infos_t *infos, enum texture text_id)
{
    sfTexture *texture = get_texture(infos, text_id);
    sfSprite *sprite = sfSprite_create();
    sfIntRect rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    if (sprite == NULL)
        return (NULL);
    sfTexture_setRepeated(texture, sfTrue);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setTextureRect(sprite, rect);
    return (sprite);
}

list_t *create_backgrounds(infos_t *infos)
{
    list_t *list = NULL;
    list_t *cpy;
    char destroy = 0;

    create_list(&list, create_background(infos, GROUND_TEXT));
    create_list(&list, create_background(infos, LANDSCAPE_TEXT));
    create_list(&list, create_background(infos, SKY_TEXT));
    cpy = list;
    for (int i = 0; i < 3 && !destroy; i++, cpy = cpy->next)
        destroy = cpy->data == NULL;
    if (destroy) {
        write(2, "Backgrounds failed to generate\n", 31);
        destroy_backgrounds(list);
        return (NULL);
    } else
        return (list);
}