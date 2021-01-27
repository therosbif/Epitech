/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** main
*/

#include "pushswap.h"

list_t *init_list(int ac, char **av)
{
    list_t *l_a = malloc(sizeof(list_t));
    list_t *tmp = NULL;

    flag = (ac > 1) ? my_strcmp(av[1], "-v") : 1;
    if (ac > 1 + flag) {
        for (int i = ac - 1; i + flag > 1; i--) {
            l_a->next = tmp;
            l_a->data = my_atoi(av[i]);
            tmp = l_a;
            l_a = malloc(sizeof(list_t));
        }
        free(l_a);
        return tmp;
    }
    return l_a;
}

void my_cocktail_sort(list_t **l_a, list_t **l_b, int nsort)
{
    list_t *begin = NULL;

    for (list_t *end = NULL; nsort; begin = (*l_b)) {
        nsort = 0;
        while ((*l_a)->next != end) {
            ((*l_a)->data > (*l_a)->next->data) ? sa(l_a, l_b, "sa ") : 1;
            pa(l_b, l_a, "pb ");
            if ((*l_b)->next && (*l_b)->data < (*l_b)->next->data)
                sa(l_b, l_a, "sb ");
        }
        end = (*l_a);
        while ((*l_b)->next != begin) {
            ((*l_b)->data < (*l_b)->next->data) ? sa(l_b, l_a, "sb ") : 1;
            pa(l_a, l_b, "pa ");
            ((*l_a)->next && (*l_a)->data > (*l_a)->next->data) ?
            sa(l_a, l_b, "sa "), nsort = 1 : 1;
        }
    }
    for (; *l_b; pa(l_a, l_b, "pa "));
}

int main(int ac, char **av)
{
    list_t *l_a = init_list(ac, av);
    list_t *l_b = NULL;
    int nsort = 1;

    offset = 0;
    (!flag) ? print_step(l_a, l_b) : 1;
    if ((ac > 2 && flag) || (ac > 3 && !flag))
        my_cocktail_sort(&l_a, &l_b, nsort);
    buff[offset - 1] = '\n';
    (offset) ? write(1, buff, offset) : write(1, "\n", 1);
    free_list(l_a);
    free_list(l_b);
    return 0;
}
