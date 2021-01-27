/*
** EPITECH PROJECT, 2019
** summands
** File description:
** evalexpr
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "opps.h"

void *my_getnbr2(char const *str);
int my_is_num(char c);
int my_is_opp(char c);
void cycle_list(linked_list_t *prev, linked_list_t *tmp);

struct do_opp operations[6] = {
    {'+', &add},
    {'-', &sub},
    {'*', &mult},
    {'/', &quot},
    {'%', &mod},
    {0, NULL}
};

int prio(char c)
{
    if (c == '*' || c == '/' || c == '%' || c == '(')
        return (3);
    if (c == '+' || c == '-')
        return (2);
    if (c == ')' || c == '\0')
        return (1);
    return (0);
}

char *my_rpn(char const *str)
{
    char *opps = malloc(my_strlen(str) + 1);
    char *str_pol = malloc(my_strlen(str) * 3 + 2);
    int j = 0;

    for (int i = 0, k = 0 ; i <= my_strlen(str) ; i++) {
        if (my_is_num(str[i])) {
            str_pol[j++] = str[i];
        } else if (prio(opps[(k == 0) ? k : k - 1]) > prio(str[i]) && 
            opps[(k < 2) ? k : k - 1] != '(') {
            for (; k > 0 ; k--) {
                str_pol[j++] = ' ';
                str_pol[j++] = (opps[k - 1] == '(') ? '6', j-- : opps[k - 1];
            }
        } if (my_is_opp(str[i])) {
            opps[k] = str[i];
            k++;
            str_pol[j++] = ' ';
        }
    }
    str_pol[j] = '\0';
    return (str_pol);
}

int calc_pol
(linked_list_t **numbs, linked_list_t *prev, linked_list_t *tmp, int i)
{
    for (char opperator ; tmp->next ;) {
        if (tmp->next->next->type == 0) {
            opperator = ((char *)tmp->next->next->data)[0];
            for (i = 0 ; operations[i].operator != opperator ; i++);
            tmp->next->next->data = operations[i].funcPtr((long)tmp->data,
                (long)tmp->next->data);
            tmp->next->next->type = 1;
            if (prev)
                prev->next = tmp->next->next;
            else
                *numbs = tmp->next->next;
            tmp = *numbs;
            prev = NULL;
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
    return ((long)(tmp->data));
}

int eval_expr(char const *str)
{
    char *str_pol = my_rpn(str);
    linked_list_t *prev = NULL;
    linked_list_t *tmp;
    char **elems = my_str_to_word_array(str_pol);
    linked_list_t *numbs = NULL;
    int i = 0;

    for (int i = 0 ; elems[i] ; i++) {
        if (my_is_opp(elems[i][0]))
            my_put_in_list(&numbs, elems[i], 0);
        else if (my_is_num(elems[i][0]))
            my_put_in_list(&numbs, my_getnbr2(elems[i]), 1);
    }
    my_rev_list(&numbs);
    tmp = numbs;
    return (calc_pol(&numbs, prev, tmp, i));
}

int  main(int ac , char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
        }
    return (84);
}