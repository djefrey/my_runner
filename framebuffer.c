/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** window managment
*/

#include <string.h>
#include "framebuffer.h"

void clear_framebuffer(framebuffer_t *buffer)
{
    memset(buffer->pixels, 0, buffer->width * buffer->height * 4);
}

void my_put_pixel(framebuffer_t *buffer, unsigned int x,
unsigned int y, sfColor color)
{
    unsigned int pos = (x + y * buffer->width) * 4;

    if (pos >= (buffer->width * buffer->height * 4 - 4))
        return;
    buffer->pixels[pos] = color.r;
    buffer->pixels[pos + 1] = color.g;
    buffer->pixels[pos + 2] = color.b;
    buffer->pixels[pos + 3] = color.a;
}

void destroy_framebuffer(framebuffer_t *buffer)
{
    free(buffer->pixels);
    free(buffer);
}

framebuffer_t *create_framebuffer(unsigned int width, unsigned int height)
{
    framebuffer_t *buffer = malloc(sizeof(framebuffer_t));
    int size = width * height * 4;

    if (buffer == NULL)
        return (NULL);
    buffer->width = width;
    buffer->height = height;
    buffer->pixels = malloc(sizeof(sfUint8) * size);
    if (buffer->pixels == NULL){
        free(buffer);
        return (NULL);
    }
    memset(buffer->pixels, 0, size);
    return (buffer);
}