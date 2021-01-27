/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** animate
*/

#include "my_defender.h"

void animate(alien_t *alien, bg_t *bg)
{
    while (alien) {
        if (GET_TIME(alien->animation_clock) > 200){
            alien->rect.left += alien->rect.width;
            if (alien->rect.left >= 160 + 200 * alien->direction)
                alien->rect.left = 200 * alien->direction;
            sfClock_restart(alien->animation_clock);
        }
        sfSprite_setTextureRect(alien->sprite, alien->rect);
        alien = alien->next;
    }
    if (GET_TIME(bg->clock) > 500) {
        bg->rect.left = 192 - bg->rect.left;
        sfClock_restart(bg->clock);
    }
    sfSprite_setTextureRect(bg->sprite, bg->rect);
}
