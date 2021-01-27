/*
** EPITECH PROJECT, 2019
** str upcase
** File description:
** puts word in upper case
*/

char *my_strupcase(char *str)
{
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
    }
    return (str);
}
