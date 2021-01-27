/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#include "runner.h"

void init_player(entities_t *ent)
{
    ent->skiaman = sfSprite_create();
    ent->skiaman_pos.x = 50;
    ent->skiaman_pos.y = 489;
    ent->rect_player = (sfIntRect){0, 0, 51, 61};
    ent->skiaman_tx = sfTexture_createFromFile(SKIER, &(ent->rect_player));
    ent->reset_player = sfClock_create();
}

void init_obstacle(entities_t *ent)
{
    ent->penguin = sfSprite_create();
    ent->penguin_pos.x = 1920;
    ent->penguin_pos.y = 700;
    ent->rect_penguin = (sfIntRect){0, 0, 43, 53};
    ent->penguin_tx = sfTexture_createFromFile(PENGUIN, &(ent->rect_penguin));
    ent->tree_small = sfSprite_create();
    ent->tree_small_pos.x = 1920;
    ent->tree_small_pos.y = 700;
    ent->tree_small_tx = sfTexture_createFromFile("sprites/tree2.png", NULL);
    ent->tree_big = sfSprite_create();
    ent->tree_big_pos.x = 1920;
    ent->tree_big_pos.y = 700;
    ent->tree_big_tx = sfTexture_createFromFile("sprites/tree2.png", NULL);
    ent->tree_christ = sfSprite_create();
    ent->tree_christ_pos.x = 1920;
    ent->tree_christ_pos.y = 700;
    ent->tree_christ_tx = sfTexture_createFromFile("sprites/tree2.png", NULL);
    ent->reset_obstacle = sfClock_create();
}

void init_setEntTexture(entities_t *ent)
{
    sfVector2f scale = {2, 2};

    sfSprite_setTexture(ent->skiaman, ent->skiaman_tx, sfTrue);
    sfSprite_setPosition(ent->skiaman, ent->skiaman_pos);
    sfSprite_setRotation(ent->skiaman, 9);
    sfSprite_setScale(ent->skiaman, scale);
    sfSprite_setTexture(ent->penguin, ent->penguin_tx, sfTrue);
    sfSprite_setRotation(ent->penguin, 9);
    sfSprite_setTexture(ent->tree_small, ent->tree_small_tx, sfTrue);
    sfSprite_setRotation(ent->tree_small, 9);
    sfSprite_setTexture(ent->tree_big, ent->tree_big_tx, sfTrue);
    sfSprite_setRotation(ent->tree_big, 9);
    sfSprite_setTexture(ent->tree_christ, ent->tree_christ_tx, sfTrue);
    sfSprite_setRotation(ent->tree_christ, 9);
}

entities_t *mv_player(entities_t *ent)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(ent->reset_player)) > 100){
        ent->rect_player.left += 52;
        (ent->rect_player.left >= 4 * 52) ? ent->rect_player.left = 0 : 1;
        ent->skiaman_tx = sfTexture_createFromFile(SKIER, &(ent->rect_player));
        sfSprite_setTexture(ent->skiaman, ent->skiaman_tx, sfTrue);
        sfClock_restart(ent->reset_player);
    }
    return ent;
}

entities_t *mv_obstacle(entities_t *ent)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(ent->reset_obstacle))
        > 5) {
        sfSprite_setPosition(ent->penguin, ent->penguin_pos);
        ent->penguin_pos.x -= 15;
        ent->penguin_pos.y -= 2.37;
        sfClock_restart(ent->reset_obstacle);
    }
    return ent;
}
