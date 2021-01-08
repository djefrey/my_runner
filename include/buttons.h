/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** buttons header
*/

#ifndef BUTTONS_H_
#define BUTTONS_H_

#include <SFML/Graphics.h>
#include "my_list.h"

typedef struct {
    sfText *text;
    sfIntRect rect;
    char hide;
    void (*on_click)(void*, sfVector2i, sfIntRect);
} button_t;

typedef void (*on_click_fct_t)(void*, sfVector2i, sfIntRect);

button_t *create_button(char *str, sfVector2f pos,
on_click_fct_t on_click, sfFont *font);
void destroy_button(button_t *button);
void destroy_buttons(list_t *list);
void set_button_position(button_t *button, sfVector2f pos);
void set_button_text(button_t *button, char *str);

#endif /* !BUTTONS_H_ */
