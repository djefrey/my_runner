/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** objects
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_list.h"
#include "my_runner.h"

void set_position(object_t *object, unsigned int x, unsigned int y)
{
    (object->pos).x = x;
    (object->pos).y = y;
    sfSprite_setPosition(object->sprite, object->pos);
}

void set_rotation(object_t *object, float rot)
{
    object->rot = rot;
    sfSprite_setRotation(object->sprite, rot);
}

void destroy_object(object_t *object)
{
    sfSprite_destroy(object->sprite);
    free(object);
}

void destroy_objects(list_t *list)
{
    list_t *tmp;

    while (list) {
        tmp = list->next;
        if (list->data)
            destroy_object((object_t*) list->data);
        free(list);
        list = tmp;
    }
}

object_t *create_object(infos_t *infos, enum object_type type,
enum texture text_id, update_fct_t up_fct)
{
    object_t *obj = malloc(sizeof(object_t));
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {0, 0};
    sfVector2f acc = {0, 0};

    if (obj == NULL) {
        sfSprite_destroy(sprite);
        return (NULL);
    }
    sfSprite_setTexture(sprite, get_texture(infos, text_id), sfFalse);
    obj->type = type;
    obj->texture = text_id;
    obj->sprite = sprite;
    obj->pos = pos;
    obj->acceleration = acc;
    obj->rot = 0;
    obj->update = up_fct;
    create_list(&(infos->objects), obj);
    return (obj);
}