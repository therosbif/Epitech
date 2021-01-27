/*
** EPITECH PROJECT, 2019
** revstr
** File description:
** reverse the str
*/

char *my_revstr(char *str)
{
    char c;
    int i = 0;

    for ( ; str[i] != '\0' ; i++) {}
    for (int j = 0 ; j < i / 2 ; j++) {
        c = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = c;
    }
    return (str);
}
