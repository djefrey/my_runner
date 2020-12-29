/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** score
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "my_runner.h"

void set_score(score_t *score)
{
    char str[13] = {0};
    int cpy_score = score->score;
    char digit;

    if (score->score == score->score_display)
        return;
    for (int i = 11; i >= 0; i--) {
        digit = 48 + cpy_score % 10;
        cpy_score /= 10;
        str[i] = digit;
    }
    score->score_display = score->score;
    sfText_setString(score->text, str);
}

void destroy_score(score_t *score)
{
    sfText_destroy(score->text);
    sfFont_destroy(score->font);
    free(score);
}

score_t *create_score(void)
{
    score_t *score = malloc(sizeof(score_t));

    if (score == NULL)
        return (NULL);
    score->score = 0;
    score->score_display = 1;
    score->text = sfText_create();
    score->font = sfFont_createFromFile("./assets/fonts/minecraftia.ttf");
    sfText_setPosition(score->text, (sfVector2f) {10, 10});
    sfText_setFont(score->text, score->font);
    sfText_setColor(score->text, sfBlack);
    set_score(score);
    return (score);
}