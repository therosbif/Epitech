/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** main
*/

#include "my_defender.h"

sfRenderWindow *set_win_param(unsigned int width,
unsigned int height, char *title, sfBool fullscreen)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window;
    int flag = (fullscreen) ? sfFullscreen : sfDefaultStyle;

    window = sfRenderWindow_create(mode, title, flag, NULL);
    if (!window)
        exit(84);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setVerticalSyncEnabled(window, sfTrue);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);

    return (window);
}

void my_destroy(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
}

void draw_sprites(sfRenderWindow *window, alien_t *alien, bg_t *bg)
{
    sfRenderWindow_drawSprite(window, bg->sprite, NULL);
    while (alien) {
        sfSprite_setPosition(alien->sprite, alien->position);
        sfRenderWindow_drawSprite(window, alien->sprite, NULL);
        alien = alien->next;
    }
}

void defender(sfRenderWindow *window)
{
    sfEvent event;
    alien_t *alien = malloc(sizeof(alien_t));
    alien_t *begin = alien;
    bg_t *bg = malloc(sizeof(bg_t));

    init_bg(bg);
    init_alien(alien);
    while (sfRenderWindow_isOpen(window)) {
        alien = begin;
        move_alien(alien);
        animate(alien, bg);
        draw_sprites(window, alien, bg);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_pollEvent(window, &event);
        while (sfRenderWindow_pollEvent(window, &event))
            (event.type == sfEvtClosed) ? sfRenderWindow_close(window) : 1;
    }
    my_destroy(window);
}

int main(int ac, char **av)
{
    sfRenderWindow *window = set_win_param(1920, 1080, "my_defender", sfFalse);

    defender(window);
    return 0;
}
