/*
** EPITECH PROJECT, 2019
** match
** File description:
** do two strings match
*/

int match(char const *s1, char const *s2)
{
    if (*s2 == '*')
        return (match(s1, s2 + 1));
    if (*s2 == 0 && (*s1 == 0 || *(s2 - 1) == '*'))
        return (1);
    if (*s1 == *s2) {
        if (*(s2 - 1) == '*')
            return (match(s1 + 1, s2 + match(s1 + 1, s2 + 1)));
        return (match(s1 + 1, s2 + 1));
    }
    if (*s1 != 0 && *(s2 - 1) == '*')
        return (match(s1 + 1, s2));
    return (0);
}
