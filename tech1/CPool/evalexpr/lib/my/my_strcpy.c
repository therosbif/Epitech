/*
** EPITECH PROJECT, 2019
** strcpy
** File description:
** copy str
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for ( ; src[i] != '\0' ; i++)
        dest[i] = src[i];
    return (dest);
}
