/*
** EPITECH PROJECT, 2019
** struct
** File description:
** opps
*/

#ifndef STRUCT_OPPS_H_
#define STRUCT_OPPS_H_

typedef struct string_t {
    char c;
    struct string_t *next;
} digits;

#define GET_SIGN(value)   ((value[0] == '-') ? -1 : 1)
#define GET_BIGGER(value1, value2)  ((value1 > value2) ? value1 : value2)
#endif
