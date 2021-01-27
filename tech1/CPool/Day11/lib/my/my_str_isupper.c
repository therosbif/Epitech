/*
** EPITECH PROJECT, 2019
** is upper
** File description:
** is str in uppercase?
*/

int my_str_isupper(char const *str)
{
    if (str[0] == '\0')
        return (1);
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] < 'Z' && str[i] > 'A')
            return (1);
    }
    return (0);
}
