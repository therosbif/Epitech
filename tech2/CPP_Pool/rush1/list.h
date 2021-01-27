/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush1-jack.goodall [WSL: Arch]
** File description:
** list
*/

#ifndef LIST_H_
#define LIST_H_

#include "object.h"
#include "container.h"

extern const Class *List;

typedef struct node {
    Object *value;
    struct node *next;
} node_t;

typedef struct ListClass_s
{
    Container base;
    Class *_type;
    node_t *_nodes;
    void (*push_front)(struct ListClass_s *, Object *);
    void (*push_back)(struct ListClass_s *, Object *);
    Object *(*pop_front)(struct ListClass_s *);
    Object *(*pop_back)(struct ListClass_s *);
} ListClass;

#endif /* !LIST_H_ */
