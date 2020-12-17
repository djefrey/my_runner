/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** print_score
*/

#include <SFML/Graphics.h>
#include "my_runner.h"
#include "framebuffer.h"
#include "score.h"

static void print_line(framebuffer_t *bf, int x, int y, char horizontal)
{
    if (horizontal) {
        for (int i = 0; i <= DIGIT_SIZE; i++)
            my_put_pixel(bf, x + i, y, DIGIT_COLOR);
    } else {
        for (int i = 0; i <= DIGIT_SIZE; i++)
            my_put_pixel(bf, x, y + i, DIGIT_COLOR);
    }
}

static void print_digit(framebuffer_t *fb, unsigned char digit, int pos)
{
    const unsigned char *lines = DIGITS[digit];

    if (lines[0])
        print_line(fb, pos, 1, 1);
    for (int i = 0; i < 2; i++) {
        if (lines[i + 1])
            print_line(fb, pos + i * DIGIT_SIZE, 1, 0);
    }
    if (lines[3])
        print_line(fb, pos, DIGIT_SIZE + 1, 1);
    for (int i = 0; i < 2; i++) {
        if (lines[i + 4])
            print_line(fb, pos + i * DIGIT_SIZE, DIGIT_SIZE + 1, 0);
    }
    if (lines[6])
        print_line(fb, pos, 2 * DIGIT_SIZE + 1, 1);
}

void set_score_display(score_t *score, int nbr)
{
    unsigned char digit;
    int first_digit_pos = 0;

    if (nbr == score->score_display)
        return;
    score->score_display = nbr;
    framebuffer_clear(score->fb);
    if (nbr < 0) {
        print_line(score->fb, 0, DIGIT_SIZE + 1, 1);
        first_digit_pos = 1;
        nbr *= -1;
    }
    for (int i = NBR_DIGITS - 1; i >= first_digit_pos; i--) {
        digit = nbr % 10;
        print_digit(score->fb, digit, i * DIGIT_SIZE + i + i * DIGIT_PADDING);
        nbr /= 10;
    }
    sfTexture_updateFromPixels(score->texture, score->fb->pixels,
    score->fb->width, score->fb->height, 0, 0);
    sfSprite_setTexture(score->sprite, score->texture, 0);
}

void score_display_destroy(score_t *score)
{
    sfTexture_destroy(score->texture);
    sfSprite_destroy(score->sprite);
    framebuffer_destroy(score->fb);
    free(score);
}

score_t *score_display_create(void)
{
    score_t *score = malloc(sizeof(score_t));
    sfVector2f sprite_pos =
    {BUFFER_HEIGHT / 3, WINDOW_HEIGHT * 0.01};

    if (score == NULL)
        return (NULL);
    score->score_display = 1;
    score->texture = sfTexture_create(BUFFER_WIDTH, BUFFER_HEIGHT);
    score->sprite = sfSprite_create();
    sfSprite_setPosition(score->sprite, sprite_pos);
    score-> fb = framebuffer_create(BUFFER_WIDTH, BUFFER_HEIGHT);
    return (score);
}