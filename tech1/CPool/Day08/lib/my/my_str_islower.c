/*
** EPITECH PROJECT, 2019
** is lower
** File description:
** is str lower case
*/

int my_str_islower(char const *str)
{
    if (str[0] == '\0')
        return (1);
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] < 'z' && str[i] > 'a')
            return (1);
    }
    return (0);
}
