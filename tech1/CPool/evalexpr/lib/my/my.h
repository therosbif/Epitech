/*
** EPITECH PROJECT, 2019
** my
** File description:
** propotypes
*/

#ifndef MY_H_
#define MY_H_

typedef struct linked_list {
    void *data;
    int type;
    struct linked_list *next;
} linked_list_t;

int my_compute_power_rec(int nb, int p);
long powerrec(long nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_is_prime(int nb);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
void my_sort_int_array(int *array, int size);
char *my_strcapitalize(char * str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char **my_str_to_word_array(char const *str);
int my_show_word_array(char * const *tab);
char *concat_params(int ac, char **av);
int my_isalphanum(char c);
int count_words(char const *str);
char **copy_over(char const *str, char **dest);
char *my_strdup(char const *src);
int my_put_in_list(linked_list_t **list, void *data, int type);
int my_list_size(linked_list_t const *begin);
int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)());
int data_eq(linked_list_t **begin, linked_list_t *prev, linked_list_t *tmp);
linked_list_t *my_find_node
(linked_list_t const *begin, void const *data_ref, int (*cmp)());
void my_add_in_sorted_list(linked_list_t **begin, void *data, int (*cmp)());
void my_rev_list(linked_list_t **begin);
void my_merge(linked_list_t **begin1, linked_list_t *begin2, int (*cmp)());
void my_concat_list(linked_list_t **begin1, linked_list_t *begin2);
int cmp_true(linked_list_t *prev, linked_list_t *curr,
linked_list_t *aft, linked_list_t **begin);
void my_sort_list(linked_list_t **begin, int (*cmp)());

#endif /*MY_H_*/