/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush1-jack.goodall
** File description:
** string
*/

#ifndef STRING_H_
#define STRING_H_

# include <sys/types.h>
# include <stdarg.h>
# include <stdbool.h>
# include <string.h>
# include "raise.h"

typedef void Object;
typedef void (*ctor_t)(Object *this, va_list *args);
typedef void (*dtor_t)(Object *this);
typedef int (*len_t)(Object *this);
typedef int (*cmp_t)(Object *this, Object *other);
typedef char *(*to_string_t)(Object *this);
typedef Object *(*binary_operator_t)(const Object *this, const Object *other);
typedef bool (*binary_comparator_t)(const Object *this, const Object *other);

typedef struct {
    const size_t        __size__;
    const char          *__name__;
    ctor_t              __ctor__;
    dtor_t              __dtor__;
    to_string_t         __str__;
    binary_operator_t   __cat__;
    binary_operator_t   __cat_c__;
    binary_comparator_t   __find__;
    len_t               __len__;
    len_t               __toi__;
    cmp_t               __cmp__;
    binary_operator_t   __cpy__;
    binary_operator_t   __cpy_c__;
}   Class;


# define str(o)                 (((Class *)o)->__str__ != NULL ? ((Class *)o)->__str__(o) : strdup(((Class *)o)->__name__))
# define cat(a, b)              ((Class *)a)->__cat__(a, b)
# define cat_c(a, b)            ((Class *)a)->__cat_c__(a, b)
# define find(a, b)             ((Class *)a)->__find__(a, b)
# define len(o)                 ((Class *)o)->__len__(o)
# define toi(o)                 ((Class *)o)->__toi__(o)
# define cmp(a, b)              ((Class *)a)->__cmp__(a, b)
# define cpy(a, b)              ((Class *)a)->__cpy__(a, b)
# define cpy_c(a, b)            ((Class *)a)->__cpy_c__(a, b)

Object  *new(const Class *class, ...);
Object  *va_new(const Class *class, va_list* ap);
void    delete(Object *ptr);

extern const Class  *String;

#endif /* !STRING_H_ */
