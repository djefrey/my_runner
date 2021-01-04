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
    if (fade->color.a + inc >= 255)
        fade->color.a = 255;
    else
        fade->color.a += inc;
}

void decrease_fade_alpha(fade_t *fade, int dec)
{
    if (fade->color.a - dec <= 0)
        fade->color.a = 0;
    else
        fade->color.a -= dec;
}

void update_fade_sprite(fade_t *fade)
{
    for (int y = 0; y < WINDOW_HEIGHT; y++) {
        for (int x = 0; x < WINDOW_WIDTH; x++)
            my_put_pixel(fade->fb, x, y, fade->color);
    }
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
    fade->color = color;
    fade->fb = fb;
    fade->texture = texture;
    fade->sprite = sprite;
    update_fade_sprite(fade);
    return (fade);
}