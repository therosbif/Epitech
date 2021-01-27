/*
** EPITECH PROJECT, 2019
** my_defender.h
** File description:
** main
*/

#ifndef MY_DEFENDER_H_
#define MY_DEFENDER_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "my.h"

typedef struct alien {
    int type;
    int health;
    int direction;
    sfTexture *texture;
    sfIntRect rect;
    sfSprite *sprite;
    sfVector2f position;
    sfClock *animation_clock;
    sfClock *clock;
    int delay;
    struct alien *next;
} alien_t;

typedef struct robot {
    int type;
    int dmg;
    sfTexture *texture;
    sfIntRect rect;
    sfSprite *sprite;
    sfVector2f position;
    sfClock *clock;
    struct robot *next;
} robot;

typedef struct bg {
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
} bg_t;

#define ALIEN1_TEXTURE "./resources/sprite/alien/alien1_texture.png"
#define ALIEN2_TEXTURE "./resources/sprite/alien/alien2_texture.png"
#define LEVEL1_TEXTURE "./resources/sprite/levels/level1_bg.png"

#define TEX(type) ((type - 1) ? ALIEN2_TEXTURE : ALIEN1_TEXTURE)
#define NEXT_ALIEN alien->next = malloc(sizeof(alien_t)), alien = alien->next

#define GET_TIME(clock) (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)))
#define POS ((int)(alien->position.x * 10000 + alien->position.y))

void move_alien(alien_t *alien);
void init_alien(alien_t *alien);
void animate(alien_t *alien, bg_t *bg);
void init_bg(bg_t *bg);

#endif
