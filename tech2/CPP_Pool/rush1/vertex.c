/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush1-jack.goodall
** File description:
** vertex
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class base;
    int x, y, z;
} VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
   (void)this;
}

static char *to_string(VertexClass *this)
{
    int default_malloc_value = 256;
    char *result = malloc(sizeof(char) * (default_malloc_value + 1));
    int expected_size = 0;

    if (!this)
        return NULL;
    else if (!result)
        raise("Could not allocate memory.\n");
    expected_size = snprintf(result, default_malloc_value,
    "<Vertex (%i, %i, %i)>", this->x, this->y, this->z);
    if (expected_size < default_malloc_value) {
        return result;
    } else {
        free(result);
        result = malloc(sizeof(expected_size + 1));
        expected_size = snprintf(result, expected_size,
        "<Vertex (%i, %i, %i)>", this->x, this->y, this->z);
        return result;
    }
}

static VertexClass *add(VertexClass *this, VertexClass *other)
{
    return new(Vertex,
        this->x + other->x,
        this->y + other->y,
        this->z + other->z);
}

static VertexClass *sub(VertexClass *this, VertexClass *other)
{
    return new(Vertex,
        this->x - other->x,
        this->y - other->y,
        this->z - other->z);
}

// Create additional functions here

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&to_string,
        .__add__ = (binary_operator_t)&add,
        .__sub__ = (binary_operator_t)&sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Vertex = (const Class *)&_description;
