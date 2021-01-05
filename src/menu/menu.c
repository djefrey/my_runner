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

static int free_and_ret(texts_t *texts, dlist_t *root, sfSprite *sprite)
{
    destroy_texts(texts);
    destroy_skins(root);
    if (sprite)
        sfSprite_destroy(sprite);
    return (84);
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
    texts_t *texts = create_texts();
    dlist_t *root = load_skins();
    dlist_t *skin = root->next;
    sfSprite *sprite = sfSprite_create();
    char *skin_path;

    if (!texts || !root || !sprite)
        return (free_and_ret(texts, root, sprite));
    set_texts(texts, "my_runner", "Appuyez sur Espace");
    sfSprite_setPosition(sprite, (sfVector2f) {930, 510});
    sfSprite_setTexture(sprite, ((skin_t*) skin->data)->texture, 0);
    while (!start_game && sfRenderWindow_isOpen(window)) {
        menu_events(window, &start_game, &skin, sprite);
        draw(window, texts, sprite);
    }
    skin_path = ((skin_t*) skin->data)->path;
    free_and_ret(texts, root, sprite);
    if (start_game)
        return (game(window, level, skin_path));
    else
        return (0);
}