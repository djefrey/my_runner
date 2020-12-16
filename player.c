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
        set_rotation(player, round(player->rot / 90.0) * 90);
}

static void detect_collision(player_t *player, object_t *block)
{
    char result = check_collision(player, block);

    switch (result) {
        case 1:
            player->dead = 1;
            break;
        case 2:
            if (block->type == BLOCK)
                set_player_on_ground(player, block->pos.y);
            else if (block->type == SPIKE)
                player->dead = 1;
            break;
        case 3:
            player->acc.y = 0;
            break;
    }
}

void update_player(object_t *obj, list_t **objs, unsigned int elapsed)
{
    player_t *player = (player_t*) obj;
    object_t *block;

    if (obj->pos.y + BLOCK_SIZE < GROUND_HEIGHT)
        obj->acc.y += GRAVITY * elapsed;
    if(obj->acc.y > 0 && obj->pos.y + BLOCK_SIZE >= GROUND_HEIGHT)
        set_player_on_ground(player, GROUND_HEIGHT);
    for (list_t *list = *objs;  list != NULL; list = list->next) {
        block = (object_t*) list->data;
        if (block->type == PLAYER)
            continue;
        detect_collision(player, block);
    }
    set_position(obj, obj->pos.x, obj->pos.y + obj->acc.y);
    if (obj->acc.y != 0)
        set_rotation(obj, obj->rot + 11.25 * elapsed);
}

void reset_player(player_t *player)
{
    player->on_ground = 1;
    player->dead = 0;
    set_position(player, PLAYER_POS, GROUND_HEIGHT - BLOCK_SIZE);
    set_rotation(player, 0);
}

player_t *create_player(infos_t *infos)
{
    object_t *obj = create_object(infos, PLAYER, PLAYER_TEXT, &update_player);
    player_t *player = (player_t*) obj;

    reset_player(player);
    return (player);
}