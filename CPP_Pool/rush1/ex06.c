/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush1-jack.goodall [WSL: Arch]
** File description:
** ex06
*/

#include "list.h"
#include "new.h"
#include "float.h"
#include <string.h>

int main(void)
{
    ListClass *my_list = new(List, Float);

    for (float i = 0; i < 10; i++)
        my_list->push_back(my_list, new(Float, i));
    printf("%s\n", str(my_list));
    my_list->pop_front(my_list);
    my_list->push_front(my_list, new(Float, 420.69f));
    my_list->pop_back(my_list);
    printf("=====================\n");
    printf("%s\n", str(my_list));
    printf("=====================\n");
    for (Iterator *it = begin(my_list); lt(it , end(my_list)); incr(it)) {
        printf("Ah, %s !\n", str(getval(it)));
    }
}