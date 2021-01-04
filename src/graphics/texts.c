/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** texts managment
*/

#include <SFML/Graphics.h>
#include "my_runner.h"

static void set_text(sfText *text, char *str)
{
    int biggest = my_get_biggest_line(str);
    int x = WINDOW_WIDTH / 2 - biggest * sfText_getCharacterSize(text) / 2;
    int y = sfText_getPosition(text).y;

    sfText_setPosition(text, (sfVector2f) {x, y});
    sfText_setString(text, str);
}

void set_texts(texts_t *texts, char *title, char *infos)
{
    set_text(texts->title, title);
    set_text(texts->infos, infos);
}

void destroy_texts(texts_t *texts)
{
    if (texts != NULL) {
        sfText_destroy(texts->title);
        sfText_destroy(texts->infos);
        free(texts);
    }
}

texts_t *create_texts(void)
{
    texts_t *texts = malloc(sizeof(texts_t));
    sfText *title = sfText_create();
    sfText *infos = sfText_create();
    sfFont *font = sfFont_createFromFile("./assets/fonts/minecraftia.ttf");

    if (texts == NULL)
        return (NULL);
    sfText_setPosition(title, (sfVector2f) {0, 180});
    sfText_setPosition(infos, (sfVector2f) {0, 720});
    sfText_setFont(title, font);
    sfText_setColor(title, sfWhite);
    sfText_setFont(infos, font);
    sfText_setColor(infos, sfWhite);
    texts->title = title;
    texts->infos = infos;
    texts->font = font;
    return (texts);
}