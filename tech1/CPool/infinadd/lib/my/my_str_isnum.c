/*
** EPITECH PROJECT, 2019
** is num
** File description:
** str is num
*/

int my_str_isnum(char const *str)
{
    if (str[0] == '\0')
        return (1);
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
            return (1);
    }
    return (0);
}
