/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** objects header
*/

#ifndef OBJECTS_H_
#define OBJECTS_H_

#include <SFML/Graphics.h>
#include "my_list.h"

enum object_type {PLAYER,
                BLOCK,
                FIRE,
                COIN,
                PISTON};

enum texture {PLAYER_TEXT,
            STONE_TEXT,
            GRASS_TEXT,
            DIRT_TEXT,
            FIRE_TEXT,
            COIN_TEXT,
            PISTON_TEXT,
            GROUND_TEXT,
            LANDSCAPE_TEXT,
            SKY_TEXT};

typedef struct object {
    enum object_type type;
    enum texture texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f acc;
    float rot;
    float time;
    int ori_x;
    void (*update)(struct object*, void*, float);
    char hide;
    char memfill[1];
} object_t;

typedef struct player {
    enum object_type type;
    enum texture texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f acc;
    float rot;
    float time;
    int ori_x;
    void (*update)(struct object*, void*, float);
    char dead;
    char on_ground;
} player_t;

void destroy_object(object_t *object, list_t **list);
void destroy_objects(list_t *list);
void set_position(object_t *object, float x, float y);
void set_rotation(object_t *object, float rot);

void reset_player(player_t *obj);
char check_collision(object_t* p_obj, object_t *obj);

void update_block(object_t *obj, void *objs, float);
void update_emerald(object_t *obj, void *infos, float);
void update_fire(object_t *obj, void *infos, float);
void reset_blocks(list_t *objs);

void update_piston_base(object_t *obj, void *infos, float);
void update_piston_head(object_t *obj, void *infos, float);

#endif /* !OBJECTS_H_ */