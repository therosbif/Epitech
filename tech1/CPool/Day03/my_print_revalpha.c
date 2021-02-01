/*
** EPITECH PROJECT, 2019
** my_print_revalpha
** File description:
** opposite of my_print_alpha
*/

int my_print_revalpha(void)
{
    int i = 'z';

    while (i >= 'a') {
        my_putchar(i);
        i--;
    }
    return (0);
}
