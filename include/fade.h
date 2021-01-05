/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** fade header
*/

#ifndef FADE_H_
#define FADE_H_

typedef struct {
    unsigned char alpha;
    framebuffer_t *fb;
    sfTexture *texture;
    sfSprite *sprite;
} fade_t;

fade_t *create_fade(sfColor color);
void destroy_fade(fade_t *fade);
void update_fade_sprite(fade_t *fade);
void increase_fade_alpha(fade_t *fade, int inc);
void decrease_fade_alpha(fade_t *fade, int inc);

#endif /* !FADE_H_ */
