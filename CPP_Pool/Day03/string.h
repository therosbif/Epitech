/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD03-jack.goodall
** File description:
** string
*/

#ifndef STRING_H_
#define STRING_H_

#include <stdlib.h>

#define MAX(x, y) ((x > y) ? x : y)
#define MIN(x, y) ((x < y) ? x : y)
#define ABS(x) ((x > 0) ? x : -x)

typedef struct string_s string_t;

typedef void (*ass_s)(string_t *this, const string_t *str);
typedef void (*ass_c)(string_t *this, const char *s);

typedef void (*app_s)(string_t *this, const string_t *ap);
typedef void (*app_c)(string_t *this, const char *ap);

typedef char (*at_)(const string_t *this, size_t pos);

typedef void (*cl)(string_t *this);

typedef int (*sz)(const string_t *this);

typedef int (*com_s)(const string_t *this, const string_t *str);
typedef int (*com_c)(const string_t *this, const char *str);

typedef size_t (*cp)(const string_t *this, char *s, size_t n, size_t pos);

typedef const char *(*cs)(const string_t *this);

typedef int (*emp)(const string_t *this);

typedef int (*f_s)(const string_t *this, const string_t *str, size_t pos);
typedef int (*f_c)(const string_t *this, const char *str, size_t pos);

typedef void (*i_s)(string_t *this, size_t pos, const string_t *str);
typedef void (*i_c)(string_t *this, size_t pos, const char *str);

typedef int (*toint)(const string_t *this);
typedef void (*prt)(const string_t *this);

typedef string_t **(*sp_s)(const string_t *this, char separator);
typedef char **(*sp_c)(const string_t *this, char separator);

typedef void (*j_c)(string_t *this, char delim, const char * const *tab);
typedef void (*j_s)(string_t *this, char delim, const string_t * const *tab);

typedef string_t *(*ss)(const string_t *this, int offset, int length);

struct string_s {
    char *str;
    ass_s assign_s;
    ass_c assign_c;
    app_s append_s;
    app_c append_c;
    at_ at;
    cl clear;
    sz size;
    com_s compare_s;
    com_c compare_c;
    cp copy;
    cs c_str;
    emp empty;
    f_s find_s;
    f_c find_c;
    i_s insert_s;
    i_c insert_c;
    toint to_int;
    sp_s split_s;
    sp_c split_c;
    prt print;
    j_s join_s;
    j_c join_c;
    ss substr;
};

int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, size_t n);
char *my_strstr(const char *haystack, const char *needle);


void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);


void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *s);

void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);

char at(const string_t *this, size_t pos);
void clear(string_t *this);
int size(const string_t *this);

int compare_c(const string_t *this, const char *str);
int compare_s(const string_t *this, const string_t *str);

size_t copy(const string_t *this, char *s, size_t n, size_t pos);
const char *c_str(const string_t *this);
int empty(const string_t *this);

int find_s(const string_t *this, const string_t *str, size_t pos);
int find_c(const string_t *this, const char *str, size_t pos);

void insert_s(string_t *this, size_t pos, const string_t *str);
void insert_c(string_t *this, size_t pos, const char *str);

int to_int(const string_t *this);
void print(const string_t *this);

string_t **split_s(const string_t *this, char separator);
char **split_c(const string_t *this, char separator);

void join_s(string_t *this, char delim, const string_t * const *tab);
void join_c(string_t *this, char delim, const char * const *tab);

string_t *substr(const string_t *this, int offset, int length);

#endif /* !STRING_H_ */
