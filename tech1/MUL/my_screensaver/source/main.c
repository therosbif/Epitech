/*
** EPITECH PROJECT, 2019
** open window
** File description:
** main
*/

#include "framebuffer.h"

sfRenderWindow *set_win_param(unsigned int width,
unsigned int height, char *title)
{
    sfRenderWindow *window = NULL;
    sfVideoMode mode;

    mode.width = width;
    mode.height = height;
    window = sfRenderWindow_create(mode, title, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

int draw_random(sfVector2i *point_a, sfVector2i *point_b, int prev_dir)
{
    int dir = prev_dir;

    (*point_a).y = (*point_b).y;
    (*point_a).x = (*point_b).x;
    (!(rand() % 19)) ? dir = rand() % 4 : 1;
    switch (dir) {
    case 0:
        (prev_dir != 1) ? (*point_b).y += 3, prev_dir = dir : 0;
    case 1:
        (prev_dir != 0) ? (*point_b).y -= 3, prev_dir = dir : 0;
    case 2:
        (prev_dir != 3) ? (*point_b).x += 3, prev_dir = dir : 0;
    case 3:
        (prev_dir != 2) ? (*point_b).x -= 3, prev_dir = dir : 0;
    }
    ((*point_b).x < 0) ? (*point_a).x = 1919, (*point_b).x = 1919 : 1;
    ((*point_b).y < 0) ? (*point_a).y = 1079, (*point_b).y = 1079 : 1;
    ((*point_b).x > 1919)? (*point_a).x = 0, (*point_b).x = 0 : 1;
    ((*point_b).y > 1079)? (*point_a).y = 0, (*point_b).y = 0 : 1;
    return prev_dir;
}

prev_dir_t select_ss(int id, framebuffer_t *fb, points_t *pts,
prev_dir_t prev_dir)
{
    switch (id) {
    case 1:
        return (pipes(fb, pts, prev_dir));
    case 2:
        shapes(fb, pts, rand() % 4 + 3);
        (*pts).point_a1.x = rand() % 1919;
        (*pts).point_a1.y = rand() % 1079;
        sleep(1);
    default:
        return prev_dir;
    }
}

void init_window(sfRenderWindow *window, framebuffer_t *fb,
sfTexture *texture, int id)
{
    sfSprite *sprite = sfSprite_create();
    sfEvent event;
    points_t pts = init_struct();
    prev_dir_t prev_dir = init_prev();

    while (sfRenderWindow_isOpen(window)) {
        prev_dir = select_ss(id, fb, &pts, prev_dir);
        sfTexture_updateFromPixels(texture, fb->pixels, 1920, 1080, 0, 0);
        sfSprite_setTexture(sprite, texture, sfFalse);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event))
            (event.type == sfEvtClosed) ? sfRenderWindow_close(window) : 1;
    }
    framebuffer_destroy(fb);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
}

int main(int ac, char **av)
{
    sfRenderWindow *window = set_win_param(1920, 1080, "my_screensaver");
    framebuffer_t *fb = framebuffer_create(1920, 1080);
    sfTexture *texture = sfTexture_create(1920, 1080);

    if (ac != 2)
        exit(84);
    if (strcmp(av[1], "-h") == 0)
        disp_usage();
    if (strcmp(av[1], "-d") == 0)
        description();
    init_window(window, fb, texture, atoi(av[1]));
    return 0;
}
