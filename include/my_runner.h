/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** my_runner
*/

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

#include <SFML/Graphics.h>
#include "my_list.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WINDOW_TITLE "my_runner"

#define FPS (float) (1 / 60.0 * 1000000)

#define PLAYER_POS 100

enum texture {PLAYER_TEXT,
            BLOCK_TEXT,
            GROUND_TEXT,
            LANDSCAPE_TEXT,
            SKY_TEXT};

enum object_type {PLAYER,
                BLOCK,
                SPIKE};

typedef struct object {
    enum object_type type;
    enum texture texture;
    sfSprite *sprite;
    sfVector2u pos;
    void (*update)(struct object*, unsigned int, unsigned int);
} object_t;

typedef struct {
    list_t *textures;
    list_t *backgrounds;
    list_t *objects;
    object_t *player;
} infos_t;

typedef void (*update_fct_t)(object_t*, unsigned int, unsigned int);

infos_t *create_infos(void);

sfTexture *get_texture(infos_t *infos, enum texture id);
void destroy_textures(list_t *textures);
list_t *load_textures(void);

void move_backgrounds(infos_t *infos, unsigned int pos);
void destroy_backgrounds(list_t *backgrounds);
list_t *create_backgrounds(infos_t *infos);

void destroy_object(object_t *object);
void destroy_objects(list_t *list);
object_t *create_object(infos_t *infos, enum object_type type,
enum texture text_id, update_fct_t up_fct);

object_t *create_player(infos_t *infos);

#endif /* !MY_RUNNER_H_ */