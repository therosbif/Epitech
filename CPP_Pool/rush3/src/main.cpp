/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-jack.goodall [WSL: Ubuntu-20.04]
** File description:
** main
*/

#include "KernelOS.hpp"
#include "IMonitorModule.hpp"
#include "Cpu.hpp"
#include "GraphWindow.hpp"
#include <cstring>
#include "print_ncurses.hpp"


int main(int ac, char **av)
{
    if (ac == 2 && (strcmp(av[1], "graph") == 0))
        loopSfml();
    else if (ac == 2 && (strcmp(av[1], "text") == 0))
        main_ncurses();
    else
        std::cout << "ERROR: Please use ./MyGKrellm [mode]" << std::endl << "The available modes are: [graph] or [text]" << std::endl;
    return 0;
}
