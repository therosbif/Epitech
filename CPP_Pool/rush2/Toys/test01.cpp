/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** test
*/

#include <iostream>
#include "LittlePony.hpp"
#include "Teddy.hpp"

Object **MyUnitTests()
{
    auto array = new Object*[2];

    array[0] = new LittlePony("happy pony");
    array[1] = new Teddy("cuddles");
    return (array);
}

int test_01()
{
    Object **array =  MyUnitTests();
    std::cout << "Type of Toy: ";
    std::cout << array[0]->getTitle() << " and " << array[0]->getType() << std::endl;
    std::cout << "Type of Toy: ";
    std::cout << array[1]->getTitle() << " and " << array[1]->getType() << std::endl;
    std::cout << "LittlePony taken: ";
    ((Toy *)array[0])->isTaken();
    std::cout << "Teddy taken: ";
    ((Toy *)array[1])->isTaken();
    delete[] array;
    return (0);
}