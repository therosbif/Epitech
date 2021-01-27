/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02A-jack.goodall
** File description:
** information_tree
*/

#include "tree_traversal.h"

bool tree_is_empty(tree_t tree)
{
    return ((tree) ? false : true);
}

void tree_node_dump(tree_node_t *tree_node, dump_func_t dump_func)
{
    (*dump_func)(tree_node->data);
}
