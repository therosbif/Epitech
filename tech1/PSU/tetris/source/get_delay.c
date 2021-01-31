/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** get_delay.c
*/

float get_delay(int level)
{
    if (level < 5)
        return 1.0f - level * 66.0f;
    if (level < 9)
        return 1.0f - level * 83.0f;
    else
        return 1.0f - level * 16.0f;
}
