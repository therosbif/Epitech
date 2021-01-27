/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush1-jack.goodall
** File description:
** string
*/

/*
** EPITECH PROJECT, 2021
** float.c
** File description:
** float
*/

#include "my_string.h"
#include "raise.h"
#include <string.h>

typedef struct
{
    Class base;
    char *str;
} StringClass;

static void String_ctor(StringClass *this, va_list *args)
{
    this->str = strdup(va_arg(*args, const char *));
}

static void String_dtor(StringClass *this)
{
    free(this->str);
}

static char *to_string(StringClass *this)
{
    char *result = strdup(this->str);

    if (!result) raise("Could not allocate memory\n");
    return result;
}

static int __len(StringClass *this)
{
    return strlen(this->str);
}

static StringClass *str_cat_c(StringClass *this, const char *other)
{
    char *result = malloc(strlen(this->str) + strlen(other) + 1);

    if (!result) raise("Could not allocate memory\n");
    strcpy(result, this->str);
    strcat(result, other);
    result[strlen(this->str) + strlen(other)] = 0;
    free(this->str);
    this->str = result;
    return this;
}

static StringClass *str_cat(StringClass *this, StringClass *other)
{
    return str_cat_c(this, other->str);
}

static bool find_in(StringClass *this, StringClass *other)
{
    return (strstr(this->str, other->str) != 0);
}

static StringClass *__cpy(StringClass *this, StringClass *other)
{
    strcpy(this->str, other->str);
    return this;
}

static StringClass *__cpy_c(StringClass *this, const char *other)
{
    strcpy(this->str, other);
    return this;
}

static int compare(StringClass *this, StringClass *that)
{
    return (strcmp(this->str, that->str));
}

static int __toi(StringClass *this)
{
    return atoi(this->str);
}

static const StringClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(StringClass),
        .__name__ = "String",
        .__ctor__ = (ctor_t)&String_ctor,
        .__dtor__ = (dtor_t)&String_dtor,
        .__str__ = (to_string_t)&to_string,
        .__cat__ = (binary_operator_t)&str_cat,
        .__cat_c__ = (binary_operator_t)&str_cat_c,
        .__find__ = (binary_comparator_t)&find_in,
        .__len__ = (len_t)&__len,
        .__toi__ = (len_t)&__toi,
        .__cmp__ = (cmp_t)&compare,
        .__cpy__ = (binary_operator_t)&__cpy,
        .__cpy_c__ = (binary_operator_t)&__cpy_c,
    },
    .str = 0
};

const Class *String = (const Class *)&_description;
