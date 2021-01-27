/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_alien
*/

#include "my_defender.h"

void set_alien(alien_t *alien, int type)
{
    alien->type = type;
    alien->health = alien->type * 100;
    alien->rect = (sfIntRect) {0, 0, 40, 40};
    alien->position = (sfVector2f) {200, -200};
    alien->texture = sfTexture_createFromFile(ALIEN1_TEXTURE, NULL);
    alien->clock = sfClock_create();
    alien->animation_clock = sfClock_create();
    alien->sprite = sfSprite_create();
    alien->next = NULL;
    alien->delay = 0;
    alien->direction = 2;
    sfSprite_setPosition(alien->sprite, alien->position);
    sfSprite_setTexture(alien->sprite, alien->texture, sfTrue);
    sfSprite_setTextureRect(alien->sprite, alien->rect);
    sfSprite_setScale(alien->sprite, (sfVector2f) {2.2, 2.2});
}

void init_alien(alien_t *alien)
{
    int fd = open("./levels/1/waves", O_RDONLY);
    char *buff = malloc(7);
    int len = read(fd, buff, 6);

    while (len && *buff != '#') {
        for (int i = 0; i < *buff - 48; i++)
            set_alien(alien, *(buff + 2) - 48);
        alien->delay = *(buff + 4) - 48;
        len = read(fd, buff, 6);
        if (*buff != '#') NEXT_ALIEN;
    }
    free(buff);
}

void init_bg(bg_t *bg)
{
    bg->rect = (sfIntRect) {0, 0, 192, 108};
    bg->texture = sfTexture_createFromFile(LEVEL1_TEXTURE, NULL);
    bg->sprite = sfSprite_create();
    bg->clock = sfClock_create();
    sfSprite_setTexture(bg->sprite, bg->texture, sfFalse);
    sfSprite_setTextureRect(bg->sprite, bg->rect);
    sfSprite_setScale(bg->sprite, (sfVector2f) {10, 10});
}
