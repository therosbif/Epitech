/*
** EPITECH PROJECT, 2019
** opps
** File description:
** +-
*/

#include <stdlib.h>
#include "my.h"

void *add(long nb1, long nb2)
{
    return ((void *)(nb1 + nb2));
}

void *sub(long nb1, long nb2)
{
    long result = nb1 - nb2;
    return ((void *)result);
}

void *mult(long nb1,long nb2)
{
    long result = nb1 * nb2;
    return ((void *)result);
}

void *quot(long nb1,long nb2)
{
    long result = nb1 / nb2;
    return ((void *)result);
}

void *mod(long nb1, long nb2)
{
    long result = nb1 % nb2;
    return ((void *)result);
}