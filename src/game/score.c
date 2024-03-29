/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** score
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "my_runner.h"

int cmp_lb_entries(void *data1, void *data2)
{
    char *str1 = (char*) data1;
    char *str2 = (char*) data2;

    for (str1 += 1; *(str1 - 1) != ' '; str1 += 1);
    for (str2 += 1; *(str2 - 1) != ' '; str2 += 1);
    for (; *str1; str1 += 1, str2 += 1) {
        if (*str1 != *str2)
            return (*str2 - *str1);
    }
    return (0);
}

void get_score_str(char str[13], int score)
{
    char digit;

    for (int i = 11; i >= 0; i--) {
        digit = 48 + score % 10;
        score /= 10;
        str[i] = digit;
    }
}

void set_score(score_t *score)
{
    char str[13] = {0};

    if (score->score == score->score_display)
        return;
    get_score_str(str, score->score);
    score->score_display = score->score;
    sfText_setString(score->text, str);
}

void destroy_score(score_t *score)
{
    if (score != NULL) {
        sfText_destroy(score->text);
        sfFont_destroy(score->font);
        free(score);
    }
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