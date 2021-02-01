/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#include <count_words.h>

int my_addtolist(words_t *words, char *word)
{
    words_t *tmp = words;

    while (tmp->next) {
        if (!my_strcmp(word, tmp->word)) {
            tmp->nb++;
            return 0;
        }
        tmp = tmp->next;
    }
    tmp->next = malloc(sizeof(words_t));
    tmp->next->word = my_strdup(word);
    tmp->next->nb = 1;
    tmp->next->next = NULL;
    return 0;
}

void my_display(words_t *words)
{
    words = words->next;
    if (!words)
        write(1, "\n", 1);
    while (words) {
        printf("%s: %d\n", words->word, words->nb);
        words = words->next;
    }
}

int main(int ac, char **av)
{
    words_t *words = malloc(sizeof(words_t));
    char *buff = my_strdup(av[1]);
    char *word;
    int end = 0;

    words->word = 0;
    words->next = NULL;
    if (ac != 2)
        return 84;
    while (!end) {
        word = buff;
        for (; *buff != ' ' && *buff != '\t' && *buff; buff++);
        if (*buff)
            *buff++ = 0;
        else
            end = 1;
        my_addtolist(&words, word);
    }
    my_display(words);
    return 0;
}
