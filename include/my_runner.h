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
#include "framebuffer.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WINDOW_TITLE "my_runner"

#define ABS(value) (value < 0 ? value * -1 : value)

#define FPS (float) (1 / 60.0 * 1000000)

#define SCROLLING_SPEED 10

#define GROUND_HEIGHT 960

#define BLOCK_SIZE 64

#define PLAYER_POS 256
#define GRAVITY 1

#define COIN_SCORE 150

#define LEVEL_END 1920

enum game_status {GAME,
                END_ANIM,
                VICTORY};

enum texture {PLAYER_TEXT,
            STONE_TEXT,
            GRASS_TEXT,
            DIRT_TEXT,
            FIRE_TEXT,
            COIN_TEXT,
            GROUND_TEXT,
            LANDSCAPE_TEXT,
            SKY_TEXT};

enum object_type {PLAYER,
                BLOCK,
                FIRE,
                COIN};

typedef struct object {
    enum object_type type;
    enum texture texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f acc;
    float rot;
    float time;
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
    void (*update)(struct object*, void*, float);
    char dead;
    char on_ground;
} player_t;

typedef struct {
    int score;
    int score_display;
    sfText *text;
    sfFont *font;
} score_t;

typedef struct {
    enum game_status status;
    int level_size;
    list_t *textures;
    list_t *backgrounds;
    list_t *objects;
    player_t *player;
    score_t *score;
} infos_t;

typedef void (*update_fct_t)(object_t*, void*, float);

infos_t *create_infos(void);
void destroy_infos(infos_t *infos);

sfTexture *get_texture(infos_t *infos, enum texture id);
void destroy_textures(list_t *textures);
list_t *load_textures(void);

void move_backgrounds(infos_t *infos, float pos);
void destroy_backgrounds(list_t *backgrounds);
list_t *create_backgrounds(infos_t *infos);

void set_position(object_t *object, int x, int y);
void set_rotation(object_t *object, float rot);
void destroy_object(object_t *object, list_t *list);
void destroy_objects(list_t *list);
object_t *create_object(infos_t *infos, enum object_type type,
enum texture text_id, update_fct_t up_fct);

player_t *create_player(infos_t *infos);
void reset_player(player_t *obj);
char check_collision(object_t* p_obj, object_t *obj);

int load_level(char *filepath, infos_t *infos);

void game_update(infos_t *infos, float elapsed, float *pos);
void end_update(infos_t *infos, float elapsed);

void update_block(object_t *obj, void *objs, float);
void update_emerald(object_t *obj, void *infos, float);
void update_fire(object_t *obj, void *infos, float);
void reset_blocks(list_t *objs, float pos);

void analyse_events(sfRenderWindow *window,
infos_t *infos, float elapsed);

score_t *create_score(void);
void destroy_score(score_t *score);
void set_score(score_t *score);

#endif /* !MY_RUNNER_H_ */