/*
** EPITECH PROJECT, 2019
** is alpha
** File description:
** is alphanum
*/

int my_str_isalpha(char const *str)
{
    if (str[0] == '\0')
        return (1);
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
            return (1);
    }
    return (0);
}
