/*
** EPITECH PROJECT, 2019
** opps
** File description:
** evalexpr
*/

#ifndef OPPS_H_
#define OPPS_H_

void *add(long nb1, long nb2);
void *sub(long nb1, long nb2);
void *mult(long nb1, long nb2);
void *quot(long nb1, long nb2);
void *mod(long nb1, long nb2);

struct do_opp{
    char operator;
    void *(*funcPtr)(long, long);
};

#endif /* !OPPS_H_ */