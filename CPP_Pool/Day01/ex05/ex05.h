/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD01-jack.goodall
** File description:
** ex05
*/

#ifndef EX05_H_
#define EX05_H_

typedef union foo foo_t;

union bar {
    int foo;
    int bar;
};

struct foo2 {
    int foo;
    union bar bar;
};

union foo {
    struct foo2 foo;
    int *bar;
};

#endif /* !EX05_H_ */
