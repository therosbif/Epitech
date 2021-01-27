/*
** EPITECH PROJECT, 2021
** int.c
** File description:
** int
*/

#include "int.h"
#include "raise.h"
#include "new.h"
#include "object.h"

typedef struct
{
    Class base;
    int value;
} IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->value = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    (void)this;
}

static char *to_string(IntClass *this)
{
    int default_malloc_value = 256;
    char *result = malloc(sizeof(char) * (default_malloc_value + 1));
    int expected_size = 0;

    if (!this)
        return NULL;
    else if (!result)
        raise("Could not allocate memory.\n");
    expected_size = snprintf(result, default_malloc_value,
    "<Int (%i)>", this->value);
    if (expected_size < default_malloc_value) {
        return result;
    } else {
        free(result);
        result = malloc(sizeof(expected_size + 1));
        expected_size = snprintf(result, expected_size,
        "<Int (%i)>", this->value);
        return result;
    }
}

static IntClass *add(IntClass *this, IntClass *other)
{
    return new(Int, this->value + other->value);
}

static IntClass *sub(IntClass *this, IntClass *other)
{
    return new(Int, this->value - other->value);
}

static IntClass *mul(IntClass *this, IntClass *other)
{
    return new(Int, this->value * other->value);
}

static IntClass *__div(IntClass *this, IntClass *other)
{
    if (other->value == 0)
        raise("Attempting to divide by zero.\n");
    return new(Int, this->value / other->value);
}

static bool equals(IntClass *this, IntClass *that)
{
    return (this->value == that->value);
}

static bool lessThan(IntClass *this, IntClass *that)
{
    return (this->value < that->value);
}

static bool greaterThan(IntClass *this, IntClass *that)
{
    return (this->value > that->value);
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&to_string,
        .__add__ = (binary_operator_t)&add,
        .__sub__ = (binary_operator_t)&sub,
        .__mul__ = (binary_operator_t)&mul,
        .__div__ = (binary_operator_t)&__div,
        .__eq__ = (binary_comparator_t)&equals,
        .__gt__ = (binary_comparator_t)&greaterThan,
        .__lt__ = (binary_comparator_t)&lessThan
    },
    .value = 0
};

const Class *Int = (const Class *)&_description;
