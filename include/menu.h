/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** menu
*/

#ifndef MENU_H_
#define MENU_H_

#include <SFML/Graphics.h>
#include "my_dlist.h"

typedef struct {
    const char *path;
    sfTexture *texture;
} skin_t;

int menu(sfRenderWindow *window, char *level);
int game(sfRenderWindow *window, char *level, int skin_id);

void menu_events(sfRenderWindow *window, char *start_game,
int *sprite_id, sfSprite *sprite);

dlist_t *load_skins(void);
void destroy_skins(dlist_t *root);

#endif /* !MENU_H_ */
