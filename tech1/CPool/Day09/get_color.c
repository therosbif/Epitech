/*
** EPITECH PROJECT, 2019
** get color
** File description:
** get color
*/

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int val = 0;

    val = red << 8;
    val += green;
    val = val << 8;
    val += blue;
    return (val);
}
