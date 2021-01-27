/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** test02
*/

#include "../rush2.hpp"

Object *MyUnitTests(Object **array)
{
    std::cout << "Teddy taken: ";
    ((Teddy *)array[0])->isTaken();
    std::cout << "Box is now open: \n";
    ((Box *)array[1])->openMe();
    std::cout << "Wrap Teddy: ";
    ((Box *)array[1])->wrapMeThat(array[0]);
    std::cout << "Wrap Box: ";
    ((GiftPaper *)array[2])->wrapMeThat(array[1]);
    return (array[2]);
}

int test_02()
{
    auto array = new Object*[4];
    array[0] = new Teddy("cuddles");
    array[1] = new Box();
    array[2] = new GiftPaper();
    array[3] = NULL;
    MyUnitTests(array);
    return (0);
}