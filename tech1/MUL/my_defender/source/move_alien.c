/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** move_alien
*/

#include "my_defender.h"

void change_dir(alien_t *alien)
{
    (POS == 2000000) ? alien->direction = 2 : 1;
    (POS == 2000100) ? alien->direction = 1 : 1;
    (POS == 4000100) ? alien->direction = 2 : 1;
    (POS == 4000300) ? alien->direction = 3 : 1;
    (POS == 2000300) ? alien->direction = 2 : 1;
    (POS == 2000900) ? alien->direction = 1 : 1;
    (POS == 10000900) ? alien->direction = 0 : 1;
    (POS == 10000800) ? alien->direction = 1 : 1;
    (POS == 13000800) ? alien->direction = 0 : 1;
    (POS == 13000600) ? alien->direction = 3 : 1;
    (POS == 8000600) ? alien->direction = 2 : 1;
    (POS == 8000700) ? alien->direction = 3 : 1;
    (POS == 5000700) ? alien->direction = 0 : 1;
    (POS == 5000400) ? alien->direction = 1 : 1;
    (POS == 11000400) ? alien->direction = 0 : 1;
}

void move_alien(alien_t *alien)
{
    while (alien) {
        if (GET_TIME(alien->clock) > 6) {
            change_dir(alien);
            switch (alien->direction) {
                case 0: alien->position.y -= 1;
                    break;
                case 1: alien->position.x += 1;
                    break;
                case 2: alien->position.y += 1;
                    break;
                case 3: alien->position.x -= 1;
                    break;
                default: break;
            }
            sfClock_restart(alien->clock);
            alien->delay += 1;
            if (alien->delay < 100) break;
            alien = alien->next;
        }
    }
}
