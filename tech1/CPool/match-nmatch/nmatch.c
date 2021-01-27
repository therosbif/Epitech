/*
** EPITECH PROJECT, 2019
** nmatch
** File description:
** number of matches
*/

int match2(char const *s1, char const *s2)
{
    if (*s2 == '*')
        return (match2(s1, s2 + 1));
    if (*s2 == 0 && (*s1 == 0 || *(s2 - 1) == '*'))
        return (1);
    if (*s1 == *s2) {
        if (*(s2 - 1) == '*')
            return (match2(s1 + 1, s2 + match2(s1 + 1, s2 + 1)));
        return (match2(s1 + 1, s2 + 1));
    }
    if (*s1 != 0 && *(s2 - 1) == '*')
        return (match2(s1 + 1, s2));
    return (0);
}

int nmatch(char const *s1, char const *s2)
{
    int n = 0;

    for (int i = 0 ; *(s1 + i) != '\0' ; i++)
        n += match2(s1 + i, s2);
    return (n);
}
