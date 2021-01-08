/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** player
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "my_runner.h"

static void set_player_on_ground(player_t *player, int ground_y)
{
    player->acc.y = 0;
    player->pos.y = ground_y - 64;
    player->on_ground = 1;
    if ((int) round(player->rot) % 90 != 0)
        set_rotation((object_t*) player, round(player->rot / 90.0) * 90);
}

static void detect_collision(player_t *player, object_t *block,
infos_t *infos, float elapsed)
{
    switch (check_collision((object_t*) player, block)) {
        case 1:
            if (block->type == COIN)
                take_coin(block, infos);
            else
                player->dead = 1;
            break;
        case 2:
            if (block->type == PISTON)
                jump_with_piston(player, block, infos, elapsed);
            else if (block->type == BLOCK)
                set_player_on_ground(player, block->pos.y);
            break;
        case 3:
            player->acc.y = 0;
            break;
    }
}

void update_player(object_t *obj, void *infos_void, float elapsed)
{
    infos_t *infos = (infos_t*) infos_void;
    player_t *player = (player_t*) obj;
    object_t *block;

    if (!player->on_ground)
        obj->acc.y += GRAVITY * elapsed * elapsed;
    player->on_ground = 0;
    for (list_t *list = infos->objects;  list != NULL; list = list->next) {
        block = (object_t*) list->data;
        if (block->type == PLAYER)
            continue;
        detect_collision(player, block, infos, elapsed);
    }
    set_position(obj, obj->pos.x, obj->pos.y + obj->acc.y);
    if (!player->on_ground)
        set_rotation(obj, obj->rot + 5 * elapsed);
}

void reset_player(player_t *player)
{
    player->on_ground = 0;
    player->dead = 0;
    set_position((object_t*) player, PLAYER_POS, GROUND_HEIGHT - BLOCK_SIZE);
    set_rotation((object_t*) player, 0);
}

player_t *create_player(infos_t *infos)
{
    object_t *obj = create_object(infos, PLAYER, PLAYER_TEXT, &update_player);
    player_t *player = (player_t*) obj;

    reset_player(player);
    return (player);
}