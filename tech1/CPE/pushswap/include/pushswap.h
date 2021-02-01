/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** pushswap
*/

#ifndef PUSHSWAP_H_
#define PUSHSWAP_H_

#include <stdlib.h>
#include <unistd.h>

typedef struct list {
    int data;
    struct list *next;
} list_t;

int my_atoi(char const *str);
int my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);

int offset(int i);
int flag(int i);
char *buff(char action, int idx, char c);

void print_buff(char *str);
void print_step(list_t *l_a, list_t *l_b);
void free_list(list_t *l_a);

void sa(list_t **l_a, list_t **l_b, char *str);
void sb(list_t **l_a, list_t **l_b);
void sc(list_t **l_a, list_t **l_b);

void pa(list_t **l_a, list_t **l_b, char *str);
void pb(list_t **l_a, list_t **l_b);

void ra(list_t **l_a, list_t **l_b, char *str);
void rb(list_t **l_a, list_t **l_b);
void rr(list_t **l_a, list_t **l_b);

void rra(list_t **l_a, list_t **l_b);
void rrb(list_t **l_a, list_t **l_b);
void rrr(list_t **l_a, list_t **l_b);

#define GET -1
#define SET 0

#endif /* !PUSHSWAP_H_ */
