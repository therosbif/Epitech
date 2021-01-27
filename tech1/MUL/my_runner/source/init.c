/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#include <runner.h>

void init_struct(paralax_t *bg)
{
    bg->sky = sfSprite_create();
    bg->sky_pos = (sfVector2f){0, 0};
    bg->sky_tx = sfTexture_createFromFile("sprites/sky.png", NULL);
    bg->mountains = sfSprite_create();
    bg->mountains_pos = (sfVector2f){0, 50};
    bg->mountains_tx = sfTexture_createFromFile("sprites/mountain.png", NULL);
    bg->snow = sfSprite_create();
    bg->snow_pos = (sfVector2f){0, 600};
    bg->snow_tx = sfTexture_createFromFile("sprites/snow.png", NULL);
    sfSprite_setRotation(bg->snow, 9);
    bg->reset_bg = sfClock_create();
}

void init_setTexture(paralax_t *bg)
{
    sfSprite_setTexture(bg->sky, bg->sky_tx, sfTrue);
    sfSprite_setTexture(bg->mountains, bg->mountains_tx, sfTrue);
    sfSprite_setTexture(bg->snow, bg->snow_tx, sfTrue);
}

void draw_sprite(sfRenderWindow *window, paralax_t *bg, entities_t *ent)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, bg->sky, NULL);
    sfRenderWindow_drawSprite(window, bg->mountains, NULL);
    sfRenderWindow_drawSprite(window, bg->snow, NULL);
    sfRenderWindow_drawSprite(window, ent->skiaman, NULL);
    sfRenderWindow_drawSprite(window, ent->penguin, NULL);
    sfRenderWindow_display(window);
}

void mv_paralax(paralax_t *bg)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(bg->reset_bg)) > 5) {
        sfSprite_setPosition(bg->sky, bg->sky_pos);
        sfSprite_setPosition(bg->mountains, bg->mountains_pos);
        sfSprite_setPosition(bg->snow, bg->snow_pos);
        bg->sky_pos.x -= 0.5;
        bg->mountains_pos.x -= 1;
        bg->snow_pos.x -= 15;
        bg->snow_pos.y -= 2.37;
        (bg->sky_pos.x <= -2000) ? bg->sky_pos.x = 0 : 1;
        (bg->mountains_pos.x <= -2000) ? bg->mountains_pos.x = 0 : 1;
        if (bg->snow_pos.x < -2000){
            bg->snow_pos.x = 0;
            bg->snow_pos.y = 600;
        }
        sfClock_restart(bg->reset_bg);
    }
}

void my_destroy(paralax_t *bg, entities_t *ent, sfRenderWindow *window)
{
    sfSprite_destroy(bg->sky);
    sfSprite_destroy(bg->mountains);
    sfSprite_destroy(bg->snow);
    sfSprite_destroy(ent->skiaman);
    sfSprite_destroy(ent->tree_small);
    sfSprite_destroy(ent->tree_big);
    sfSprite_destroy(ent->tree_christ);
    sfSprite_destroy(ent->penguin);
    sfTexture_destroy(bg->sky_tx);
    sfTexture_destroy(bg->mountains_tx);
    sfTexture_destroy(bg->snow_tx);
    sfTexture_destroy(ent->skiaman_tx);
    sfTexture_destroy(ent->penguin_tx);
    sfTexture_destroy(ent->tree_small_tx);
    sfTexture_destroy(ent->tree_big_tx);
    sfTexture_destroy(ent->tree_christ_tx);
    sfRenderWindow_destroy(window);
}
