/*
** EPITECH PROJECT, 2019
** isneg
** File description:
** test if negative
*/

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return (0);
}
