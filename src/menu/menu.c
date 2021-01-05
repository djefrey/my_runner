/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** menu
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "my_dlist.h"
#include "menu.h"
#include "texts.h"

static int free_and_ret(texts_t *texts, sfTexture *texture, sfSprite *sprite)
{
    destroy_texts(texts);
    if (texture)
        sfTexture_destroy(texture);
    if (sprite)
        sfSprite_destroy(sprite);
    return (84);
}

static sfSprite *create_skin_sprite(sfTexture *texture)
{
    sfSprite *sprite;

    if (!texture)
        return (NULL);
    sprite = sfSprite_create();
    if (!sprite)
        return (NULL);
    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setTextureRect(sprite, (sfIntRect) {0, 0, 64, 64});
    return (sprite);
}

static void draw(sfRenderWindow *window, texts_t *texts, sfSprite *sprite)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawText(window, texts->title, NULL);
    sfRenderWindow_drawText(window, texts->infos, NULL);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
}

int menu(sfRenderWindow *window, char *level)
{
    char start_game = 0;
    int sprite_id = 0;
    texts_t *texts = create_texts();
    sfTexture *skin_text = sfTexture_createFromFile("./assets/textures/player.png", 0);
    sfSprite *sprite = create_skin_sprite(skin_text);

    if (!texts || !skin_text || !sprite)
        return (free_and_ret(texts, skin_text, sprite));
    set_texts(texts, "my_runner", "Appuyez sur Espace");
    sfSprite_setPosition(sprite, (sfVector2f) {930, 510});
    while (!start_game && sfRenderWindow_isOpen(window)) {
        menu_events(window, &start_game, &sprite_id, sprite);
        draw(window, texts, sprite);
    }
    free_and_ret(texts, skin_text, sprite);
    if (start_game)
        return (game(window, level, sprite_id));
    else
        return (0);
}