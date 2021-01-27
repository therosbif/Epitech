/*
** EPITECH PROJECT, 2019
** my swap
** File description:
** swap 2 ints
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
