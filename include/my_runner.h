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

#define ABS(value) (value < 0 ? value * -1 : value)

#define FPS (float) (1 / 60.0 * 1000000)

#define SCROLLING_SPEED 10

#define GROUND_HEIGHT 896

#define BLOCK_SIZE 64

#define PLAYER_POS 128
#define GRAVITY 1

enum texture {PLAYER_TEXT,
            BLOCK_TEXT,
            SPIKE_TEXT,
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
    sfVector2f pos;
    sfVector2f acc;
    float rot;
    long time;
    char dead;
    void (*update)(struct object*, list_t**, unsigned int);
} object_t;

typedef struct {
    list_t *textures;
    list_t *backgrounds;
    list_t *objects;
    object_t *player;
} infos_t;

typedef void (*update_fct_t)(object_t*, list_t**, unsigned int);

infos_t *create_infos(void);

sfTexture *get_texture(infos_t *infos, enum texture id);
void destroy_textures(list_t *textures);
list_t *load_textures(void);

void move_backgrounds(infos_t *infos, unsigned int pos);
void destroy_backgrounds(list_t *backgrounds);
list_t *create_backgrounds(infos_t *infos);

void set_position(object_t *object, int x, int y);
void set_rotation(object_t *object, float rot);
void destroy_object(object_t *object, list_t *list);
void destroy_objects(list_t *list);
object_t *create_object(infos_t *infos, enum object_type type,
enum texture text_id, update_fct_t up_fct);

object_t *create_player(infos_t *infos);
void reset_player(object_t *obj);
char check_collision(object_t* p_obj, object_t *obj);

int load_level(char *filepath, infos_t *infos);

void update_block(object_t *obj, list_t **objs, unsigned int);
void reset_blocks_pos(list_t *objs, unsigned int pos);

#endif /* !MY_RUNNER_H_ */