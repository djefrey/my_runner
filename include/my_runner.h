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

#include "objects.h"
#include "fade.h"
#include "score.h"
#include "texts.h"

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
                PAUSE,
                END_ANIM,
                VICTORY};

typedef struct {
    enum game_status status;
    int level_size;
    list_t *textures;
    list_t *backgrounds;
    list_t *objects;
    player_t *player;
    score_t *score;
    fade_t *fade;
    texts_t *texts;
} infos_t;

typedef void (*update_fct_t)(object_t*, void*, float);

int game(sfRenderWindow *window, char *level);

infos_t *create_infos(void);
void destroy_infos(infos_t *infos);

sfTexture *get_texture(infos_t *infos, enum texture id);
void destroy_textures(list_t *textures);
list_t *load_textures(void);

void move_backgrounds(infos_t *infos, float pos);
void destroy_backgrounds(list_t *backgrounds);
list_t *create_backgrounds(infos_t *infos);

int load_level(char *filepath, infos_t *infos);

void game_update(infos_t *infos, float elapsed, float *pos);
void end_update(infos_t *infos, float elapsed);

void game_draw(sfRenderWindow *window, infos_t *infos);
void end_draw(sfRenderWindow *window, infos_t *infos);
void victory_draw(sfRenderWindow *window, infos_t *infos);

void analyse_events(sfRenderWindow *window,
infos_t *infos, float elapsed);

object_t *create_object(infos_t *infos, enum object_type type,
enum texture text_id, update_fct_t up_fct);
player_t *create_player(infos_t *infos);

#endif /* !MY_RUNNER_H_ */