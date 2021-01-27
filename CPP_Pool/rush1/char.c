/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush1-jack.goodall [WSL: Arch]
** File description:
** char
*/

#include "char.h"
#include "raise.h"
#include "new.h"
#include "object.h"

typedef struct
{
    Class base;
    char value;
} CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->value = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    (void)this;
}

static char *to_string(CharClass *this)
{
    int default_malloc_value = 256;
    char *result = malloc(sizeof(char) * (default_malloc_value + 1));
    int expected_size = 0;

    if (!this)
        return NULL;
    else if (!result)
        raise("Could not allocate memory.\n");
    expected_size = snprintf(result, default_malloc_value,
    "<Char (%c)>", this->value);
    if (expected_size < default_malloc_value) {
        return result;
    } else {
        free(result);
        result = malloc(sizeof(expected_size + 1));
        expected_size = snprintf(result, expected_size,
        "<Char (%c)>", this->value);
        return result;
    }
}

static CharClass *add(CharClass *this, CharClass *other)
{
    return new(Char, this->value + other->value);
}

static CharClass *sub(CharClass *this, CharClass *other)
{
    return new(Char, this->value - other->value);
}

static CharClass *mul(CharClass *this, CharClass *other)
{
    return new(Char, this->value * other->value);
}

static CharClass *__div(CharClass *this, CharClass *other)
{
    if (other->value == 0)
        raise("Attempting to divide by zero.\n");
    return new(Char, this->value / other->value);
}

static bool equals(CharClass *this, CharClass *that)
{
    return (this->value == that->value);
}

static bool lessThan(CharClass *this, CharClass *that)
{
    return (this->value < that->value);
}

static bool greaterThan(CharClass *this, CharClass *that)
{
    return (this->value > that->value);
}

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
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

const Class *Char = (const Class *)&_description;
