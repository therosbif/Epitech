/*
** EPITECH PROJECT, 2019
** strcat
** File description:
** concentrate two str
*/

char *my_strcat(char *dest, char const *src)
{
    int j = my_strlen(dest);

    my_strcpy(dest + j, src);
    return (dest);
}
