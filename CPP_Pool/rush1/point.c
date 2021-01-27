/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
    int y;
} PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    (void)this;
}

static char *to_string(PointClass *this)
{
    int default_malloc_value = 256;
    char *result = malloc(sizeof(char) * (default_malloc_value + 1));
    int expected_size = 0;

    if (!this)
        return NULL;
    else if (!result)
        raise("Could not allocate memory.\n");
    expected_size = snprintf(result, default_malloc_value,
    "<Point (%i, %i)>", this->x, this->y);
    if (expected_size < default_malloc_value) {
        return result;
    } else {
        free(result);
        result = malloc(sizeof(expected_size + 1));
        expected_size = snprintf(result, expected_size,
        "<Point (%i, %i)>", this->x, this->y);
        return result;
    }
}

static PointClass *add(PointClass *this, PointClass *other)
{
    return new(Point, this->x + other->x, this->y + other->y);
}

static PointClass *sub(PointClass *this, PointClass *other)
{
    return new(Point, this->x - other->x, this->y - other->y);
}

// Create additional functions here

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&to_string,
        .__add__ = (binary_operator_t)&add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;
