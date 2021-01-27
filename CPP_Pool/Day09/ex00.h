/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD09-jack.goodall
** File description:
** ex00
*/

#ifndef EX00_H_
#define EX00_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct cthulhu_s {
    int m_power;
    char *m_name;
} cthulhu_t;

typedef struct koala_s {
    cthulhu_t m_parent;
    char m_is_a_legend;
} koala_t;


cthulhu_t *new_cthulhu();

void print_power(cthulhu_t *this);
void attack(cthulhu_t *this);
void sleeping(cthulhu_t *this);

koala_t *new_koala(char *name, char is_a_legend);

void eat(koala_t *this);


#endif /* !EX00_H_ */
