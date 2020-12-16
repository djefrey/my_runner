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

void set_position(object_t *object, int x, int y)
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

void destroy_object(object_t *object, list_t *list)
{
    if (list)
        my_delete_node(list, object);
    sfSprite_destroy(object->sprite);
    free(object);
}

void destroy_objects(list_t *list)
{
    list_t *tmp;

    while (list) {
        tmp = list->next;
        if (list->data)
            destroy_object((object_t*) list->data, NULL);
        free(list);
        list = tmp;
    }
}

object_t *create_object(infos_t *infos, enum object_type type,
enum texture text_id, update_fct_t up_fct)
{
    object_t *obj = malloc(sizeof(object_t));
    sfSprite *sprite = sfSprite_create();

    if (obj == NULL) {
        sfSprite_destroy(sprite);
        return (NULL);
    }
    sfSprite_setTexture(sprite, get_texture(infos, text_id), sfFalse);
    sfSprite_setOrigin(sprite, ((sfVector2f) {32, 32}));
    obj->type = type;
    obj->texture = text_id;
    obj->sprite = sprite;
    obj->pos = ((sfVector2f) {0, 0});
    obj->acc = ((sfVector2f) {0, 0});
    obj->rot = 0;
    obj->update = up_fct;
    obj->hide = 0;
    create_list(&(infos->objects), obj);
    return (obj);
}