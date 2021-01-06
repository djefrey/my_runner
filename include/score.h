/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** score header
*/

#ifndef SCORE_H_
#define SCORE_H_

#include <SFML/Graphics.h>

typedef struct {
    int score;
    int score_display;
    sfText *text;
    sfFont *font;
} score_t;

score_t *create_score(void);
void destroy_score(score_t *score);
void set_score(score_t *score);
void get_score_str(char str[13], int score);

int cmp_lb_entries(void *data1, void *data2);

#endif /* !SCORE_H_ */
