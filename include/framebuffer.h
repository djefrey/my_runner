/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** framebuffer
*/

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

#include <SFML/Graphics.h>
#include <stdlib.h>

typedef struct {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void framebuffer_destroy(framebuffer_t *buffer);
void my_put_pixel(framebuffer_t *buffer, unsigned int x, unsigned int y,
sfColor color);
void framebuffer_clear(framebuffer_t *framebuffer);

#endif /* !FRAMEBUFFER_H_ */