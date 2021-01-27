/*
** EPITECH PROJECT, 2019
** evil str
** File description:
** reverse string
*/

char *my_evil_str(char *str)
{
    int len = my_strlen(str);
    char c;

    for (int i = 0 ; i < len / 2 ; i++) {
        c = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = c;
    }
    return (str);
}
