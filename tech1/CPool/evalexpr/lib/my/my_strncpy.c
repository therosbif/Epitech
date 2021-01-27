/*
** EPITECH PROJECT, 2019
** cpynstr
** File description:
** copy n chars from str
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int j = 0;

    for ( ; src[j] != '\0' ; j++);
    for (int i = 0 ; i < j && i < n ; i++)
        dest[i] = src[i];
    for ( ; j < n ; j++)
        dest[j] = '\0';
    return (dest);
}
