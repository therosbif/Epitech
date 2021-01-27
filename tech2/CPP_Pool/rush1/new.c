/*
** EPITECH PROJECT, 2021
** new.c
** File description:
** constructor
*/

#include "new.h"
#include <stdlib.h>
#include <string.h>
#include "object.h"
#include "raise.h"


Object *va_new(const Class *class, va_list *ap)
{
    Object *result = malloc(class->__size__);

    if (!result)
        raise("Could not allocate memory.\n");
    result = memcpy(result, class, class->__size__);
    if (!result)
        raise("Could not copy memory\n");
    if (class->__ctor__)
        class->__ctor__(result, ap);
    return result;
}

void delete(Object *ptr)
{
    if (((Class *)ptr)->__dtor__)
        ((Class *)ptr)->__dtor__(ptr);
    free(ptr);
}

Object *new(const Class *class, ...)
{
    va_list ap;
    Object *new_object;

    va_start(ap, class);
    new_object = va_new(class, &ap);
    va_end(ap);
    return new_object;
}
