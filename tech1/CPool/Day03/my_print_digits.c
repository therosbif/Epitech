/*
** EPITECH PROJECT, 2019
** my print digits
** File description:
** print digits 0-9
*/

int my_print_digits(void)
{
    int i = '0';

    while (i <= '9'){
        my_putchar(i);
        i++;
    }
    return (0);
}
