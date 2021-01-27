/*
** EPITECH PROJECT, 2019
** capitalize
** File description:
** capitalize
*/

char *my_strcapitalize(char * str)
{
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] = str[0] - 32;
    for (int i = 1 ; str[i] != '\0' ; i++) {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] = str[i] + 32;
        if (str[i] >= 'a' && str[i] <= 'z' && str[i - 1] < 48)
            str[i] = str[i] - 32;
    }
    return (str);
}
