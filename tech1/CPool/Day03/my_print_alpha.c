/*
** EPITECH PROJECT, 2019
** my_print_alpha
** File description:
** displays ascii ascending
*/

int my_print_alpha(void)
{
    char c = 'a';

    while (c <= 'z') {
        my_putchar(c);
        c++;
    }
    return (0);
}
