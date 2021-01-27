/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** main
*/

#include "runner.h"

sfRenderWindow *set_win_param(unsigned int width,
unsigned int height, char *title)
{
    sfRenderWindow *window = NULL;
    sfVideoMode mode = sfVideoMode_getDesktopMode();

    mode.width = width;
    mode.height = height;
    window = sfRenderWindow_create(mode, title, sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

void game(sfRenderWindow *window)
{
    sfEvent event;
    paralax_t *bg = malloc(sizeof(paralax_t *));
    entities_t *ent = malloc(sizeof(entities_t *));

    init_struct(bg);
    init_player(ent);
    init_setTexture(bg);
    init_setEntTexture(ent);
    while (sfRenderWindow_isOpen(window)) {
        draw_sprite(window, bg, ent);
        mv_paralax(bg);
        ent = mv_obstacle(ent);
        ent = mv_player(ent);
        while (sfRenderWindow_pollEvent(window, &event))
            (event.type == sfEvtClosed) ? sfRenderWindow_close(window) : 1;
    }
    my_destroy(bg, ent, window);
}

int main()
{
    sfRenderWindow *window = set_win_param(1920, 1080, "my_screensaver");
    game(window);
    return 0;
}
