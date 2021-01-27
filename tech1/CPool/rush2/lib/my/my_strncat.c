/*
** EPITECH PROJECT, 2019
** strncat
** File description:
** append n chars to dest
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int j = my_strlen(dest);

    my_strncpy(dest + j, src, nb);
    return (dest);
}
