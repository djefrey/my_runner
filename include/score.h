/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** score header
*/

#ifndef SCORE_H_
#define SCORE_H_

typedef struct {
    int score;
    int score_display;
    sfText *text;
    sfFont *font;
} score_t;

score_t *create_score(void);
void destroy_score(score_t *score);
void set_score(score_t *score);

#endif /* !SCORE_H_ */
