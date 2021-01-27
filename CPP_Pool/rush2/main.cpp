/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** main
*/

#include "rush2.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: ./factory 'ex number'" << std::endl;
        return (0);
    }
    if (atoi(av[1]) == 1) {
        std::cout << "-------Starting Ex01-------" << std::endl;
        test_01();
        std::cout << "--Ex01 Finished--" << std::endl;
    }
    if (atoi(av[1]) == 2) {
        std::cout << "-------Starting Ex02-------" << std::endl;
        test_02();
        std::cout << "--Ex02 Finished--" << std::endl;
    }
    if (atoi(av[1]) == 3) {
        std::cout << "-------Starting Ex03-------" << std::endl;
        test_03();
        std::cout << "--Ex03 Finished--" << std::endl;
    }
    if (atoi(av[1]) == 4) {
        std::cout << "-------Starting Ex04-------" << std::endl;
        test_04();
        std::cout << "--Ex04 Finished--" << std::endl;
    }
    std::cout << "Rush2 Finished" << std::endl;
}