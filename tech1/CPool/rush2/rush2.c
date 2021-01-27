/*
** EPITECH PROJECT, 2019
** rush2
** File description:
** guess language
*/

#include "my.h"
#include "probs.h"

int difference(const int *lan, char *str, int total);

float my_count(char *str, char c)
{
    int casetest;
    float n = 0;

    for (int i = 0 ; str[i] != '\0' ; i++) {
        casetest = (str[i] <= 'z' && str[i] >= 'a') ? 32 : -32;
        if (str[i] == c || str[i] == c + casetest)
            n++;
    }
    return (n);
}

float my_count_alpha(char *str)
{
    float p = 0;

    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')
            p++;
    }
    return (p);
}

int my_language(char *str)
{
    int lang_prob[4] = {0};
    int total = my_count_alpha(str);
    int index = 0;

    lang_prob[0] = difference(ENG, str, total);
    lang_prob[1] = difference(FRA, str, total);
    lang_prob[2] = difference(SPA, str, total);
    lang_prob[3] = difference(GER, str, total);
    for (int max = 0 ; max < 4 ; max++)
        index = (lang_prob[index] > lang_prob[max]) ? max : index;
    return (index);
}

int difference(const int *lan, char *str, int total)
{
    float diff = 0;
    int difftot = 0;
    char lettres[26] = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0 ; i < 26 ; i++) {
        diff = ((my_count(str, lettres[i]) / total) * 10000) - lan[i];
        difftot += (diff < 0) ? -1 * diff : diff;
    }
    return (difftot);
}
