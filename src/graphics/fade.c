/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** fade
*/

#include <SFML/Graphics.h>
#include "my_runner.h"
#include "framebuffer.h"

void increase_fade_alpha(fade_t *fade, int inc)
{
    if (fade->alpha + inc >= 255)
        fade->alpha = 255;
    else
        fade->alpha += inc;
}

void decrease_fade_alpha(fade_t *fade, int dec)
{
    if (fade->alpha - dec <= 0)
        fade->alpha = 0;
    else
        fade->alpha -= dec;
}

void update_fade_sprite(fade_t *fade)
{
    for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; i++)
        fade->fb->pixels[i * 4 + 3] = fade->alpha;
    sfTexture_updateFromPixels(fade->texture, fade->fb->pixels,
    WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
}

void destroy_fade(fade_t *fade)
{
    sfSprite_destroy(fade->sprite);
    sfTexture_destroy(fade->texture);
    destroy_framebuffer(fade->fb);
    free(fade);
}

fade_t *create_fade(sfColor color)
{
    fade_t *fade = malloc(sizeof(fade_t));
    framebuffer_t *fb;
    sfTexture *texture = sfTexture_create(WINDOW_WIDTH, WINDOW_HEIGHT);
    sfSprite *sprite = sfSprite_create();

    if (fade == NULL)
        return (NULL);
    if ((fb = create_framebuffer(WINDOW_WIDTH, WINDOW_HEIGHT)) == NULL) {
        free(fade);
        sfTexture_destroy(texture);
        sfSprite_destroy(sprite);
        return (NULL);
    }
    sfSprite_setTexture(sprite, texture, 0);
    fade->alpha = color.a;
    fade->fb = fb;
    fade->texture = texture;
    fade->sprite = sprite;
    update_fade_sprite(fade);
    return (fade);
}