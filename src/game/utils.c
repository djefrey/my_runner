/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** physics
*/

#include "my_runner.h"

void quit_fct(void *infos_void, sfVector2i click_pos, sfIntRect rect)
{
    infos_t *infos = (infos_t*) infos_void;
    const sfView* view = sfRenderWindow_getView(infos->window);
    sfVector2f real_pos =
    sfRenderWindow_mapPixelToCoords(infos->window, click_pos, view);

    if (real_pos.x >= rect.left && real_pos.x <= rect.left + rect.width
    && real_pos.y >= rect.top && real_pos.y <= rect.top + rect.height)
    sfRenderWindow_close(infos->window);
}

void jump_with_piston(object_t *player, object_t *block,
infos_t *infos, float elapsed)
{
    set_position((object_t*) player, player->pos.x, player->pos.y - 64);
    player->acc.y -= 30 * elapsed;
    extend_piston(block, infos);
    play_sound(infos->audio, PISTON_SOUND);
}

void take_coin(object_t *block, infos_t *infos)
{
    block->hide = 1;
    infos->score->score += COIN_SCORE;
    play_sound(infos->audio, COIN_SOUND);
}

char check_collision(object_t* p_obj, object_t *obj)
{
    int p_posx = p_obj->pos.x + p_obj->acc.x;
    int p_top = p_obj->pos.y + p_obj->acc.y;
    int p_bot = p_top + BLOCK_SIZE;
    int o_posx = obj->pos.x;
    int o_top = obj->pos.y;
    int o_bot = o_top + BLOCK_SIZE;

    if (obj->hide)
        return (0);
    if ((p_posx >= o_posx && p_posx <= o_posx + BLOCK_SIZE) || (p_posx
    + BLOCK_SIZE >= o_posx && p_posx + BLOCK_SIZE <= o_posx + BLOCK_SIZE)) {
        if (p_obj->acc.y >= 0 && ABS(p_bot - o_top) <= 32)
            return (2);
        else if (p_obj->acc.y < 0 && ABS(o_bot - p_top) <= 32)
            return (3);
        else
            return ((p_top <= o_top && p_bot >= o_top) ||
            (p_top >= o_top && p_top <= o_bot));
    }
    return (0);
}