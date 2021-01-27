/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02A-jack.goodall
** File description:
** modification_tree
*/

#include "tree_traversal.h"
#include "queue.h"
#include <stdlib.h>

bool init_tree(tree_t *tree_ptr, void *data)
{
    tree_t new = malloc(sizeof(tree_node_t));

    if (!new) return false;
    new->data = data;
    *tree_ptr = new;
    return true;
}

tree_node_t *tree_add_child(tree_node_t *tree_node, void *data)
{
    queue_
}
