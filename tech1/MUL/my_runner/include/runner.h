/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** runner
*/

#ifndef RUNNER_H_
#define RUNNER_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct paralax {
    sfSprite *sky;
    sfVector2f sky_pos;
    sfTexture *sky_tx;
    sfSprite *mountains;
    sfVector2f mountains_pos;
    sfTexture *mountains_tx;
    sfSprite *snow;
    sfVector2f snow_pos;
    sfTexture *snow_tx;
    sfClock *reset_bg;
} paralax_t;

typedef struct entities {
    sfSprite *skiaman;
    sfVector2f skiaman_pos;
    sfTexture *skiaman_tx;
    sfSprite *penguin;
    sfVector2f penguin_pos;
    sfTexture *penguin_tx;
    sfSprite *tree_big;
    sfVector2f tree_big_pos;
    sfTexture *tree_big_tx;
    sfSprite *tree_small;
    sfVector2f tree_small_pos;
    sfTexture *tree_small_tx;;
    sfSprite *tree_christ;
    sfVector2f tree_christ_pos;
    sfTexture *tree_christ_tx;
    sfIntRect rect_player;
    sfIntRect rect_penguin;
    sfClock *reset_player;
    sfClock *reset_obstacle;
} entities_t;

#define SKIER "sprites/skiaman.png"
#define PENGUIN "sprites/penguin.png"

void init_struct(paralax_t *bg);
void init_setTexture(paralax_t *bg);
void init_player(entities_t *ent);
void init_setEntTexture(entities_t *ent);
void draw_sprite(sfRenderWindow *window, paralax_t *bg, entities_t *ent);
void mv_paralax(paralax_t *bg);
entities_t *mv_player(entities_t *ent);
entities_t *mv_obstacle(entities_t *ent);
void my_destroy(paralax_t *bg, entities_t *ent, sfRenderWindow *window);

#endif /* !RUNNER_H_ */
