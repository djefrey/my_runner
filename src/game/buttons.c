/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** buttons
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_list.h"
#include "buttons.h"

void set_button_text(button_t *button, char *str)
{
    int len = my_strlen(str);
    int width = sfText_getCharacterSize(button->text) * len;
    sfIntRect rect = button->rect;

    sfText_setString(button->text, str);
    button->rect = (sfIntRect) {rect.left, rect.top, width, rect.height};
}

void set_button_position(button_t *button, sfVector2f pos)
{
    sfIntRect rect = button->rect;

    sfText_setPosition(button->text, pos);
    button->rect = (sfIntRect) {pos.x, pos.y, rect.width, rect.height};
}

void destroy_buttons(list_t *list)
{
    button_t *button;

    while (list) {
        button = (button_t*) list->data;
        destroy_button(button);
        list = list->next;
    }
}

void destroy_button(button_t *button)
{
    if (button) {
        sfText_destroy(button->text);
        free(button);
    }
}

button_t *create_button(char *str, sfVector2f pos,
on_click_fct_t on_click, sfFont *font)
{
    button_t *button = malloc(sizeof(button_t));
    sfText *text;
    int len = my_strlen(str);
    int width;
    int height;

    if (!button)
        return (NULL);
    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setString(text, str);
    sfText_setPosition(text, pos);
    width = sfText_getCharacterSize(text) * len;
    height = sfText_getCharacterSize(text) * 1.5f;
    button->text = text;
    button->rect = (sfIntRect) {pos.x, pos.y, width, height};
    button->hide = 0;
    button->on_click = on_click;
    return (button);
}