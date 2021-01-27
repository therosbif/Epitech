/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD02M-jack.goodall
** File description:
** castmainia
*/

#include "castmania.h"
#include <stdio.h>

void exec_operation(instruction_type_t instruction_type, void *data)
{
    int is_int = 0;

    if (instruction_type == ADD_OPERATION) {
        exec_add((addition_t *)(((instruction_t *)data)->operation));
        if ((((instruction_t *)data)->output_type == VERBOSE))
            printf("%d\n",
            ((addition_t *)(((instruction_t *)data)->operation))->add_op.res);
    } else if (instruction_type == DIV_OPERATION) {
        exec_div((division_t *)(((instruction_t *)data)->operation));
        if ((((instruction_t *)data)->output_type == VERBOSE)) {
            is_int = (((division_t *)((
                (instruction_t *)data)->operation))->div_type == INTEGER);
            if (is_int) {
                printf("%d\n", ((integer_op_t *)(((division_t *)(
                    ((instruction_t *)data)->operation))->div_op))->res);
            } else {
                printf("%f\n", ((decimale_op_t *)(((division_t *)(
                    ((instruction_t *)data)->operation))->div_op))->res);
            }
        }
    }
}

void exec_instruction(instruction_type_t instruction_type, void *data)
{
    if (instruction_type == PRINT_INT)
        printf("%d\n", *((int *)data));
    else if (instruction_type == PRINT_FLOAT)
        printf("%f\n", *((float *)data));
    else
        exec_operation(instruction_type, data);
}
