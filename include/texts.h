/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** texts header
*/

#ifndef TEXTS_H_
#define TEXTS_H_

typedef struct {
    sfText *title;
    sfText *infos;
    sfFont *font;
} texts_t;

texts_t *create_texts(void);
void destroy_texts(texts_t *texts);
void set_texts(texts_t *texts, char *title, char *infos);

#endif /* !TEXTS_H_ */