/*
** EPITECH PROJECT, 2021
** float.c
** File description:
** float
*/

#include "float.h"
#include "raise.h"
#include "new.h"
#include "object.h"

typedef struct
{
    Class base;
    float value;
} FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->value = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    (void)this;
}

static char *to_string(FloatClass *this)
{
    int default_malloc_value = 256;
    char *result = malloc(sizeof(char) * (default_malloc_value + 1));
    int expected_size = 0;

    if (!this)
        return NULL;
    else if (!result)
        raise("Could not allocate memory.\n");
    expected_size = snprintf(result, default_malloc_value,
    "<Float (%f)>", this->value);
    if (expected_size < default_malloc_value) {
        return result;
    } else {
        free(result);
        result = malloc(sizeof(expected_size + 1));
        expected_size = snprintf(result, expected_size,
        "<Float (%f)>", this->value);
        return result;
    }
}

static FloatClass *add(FloatClass *this, FloatClass *other)
{
    return new(Float, this->value + other->value);
}

static FloatClass *sub(FloatClass *this, FloatClass *other)
{
    return new(Float, this->value - other->value);
}

static FloatClass *mul(FloatClass *this, FloatClass *other)
{
    return new(Float, this->value * other->value);
}

static FloatClass *__div(FloatClass *this, FloatClass *other)
{
    if (other->value == 0)
        raise("Attempting to divide by zero.\n");
    return new(Float, this->value / other->value);
}

static bool equals(FloatClass *this, FloatClass *that)
{
    return (this->value == that->value);
}

static bool lessThan(FloatClass *this, FloatClass *that)
{
    return (this->value < that->value);
}

static bool greaterThan(FloatClass *this, FloatClass *that)
{
    return (this->value > that->value);
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
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

const Class *Float = (const Class *)&_description;
