/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-jack.goodall [WSL: Ubuntu-20.04]
** File description:
** ncurses
*/

#include <iostream>
#include <fstream>
#include <ncurses.h>
#include "Hostname.hpp"


class print_ncurses {
    public:
        print_ncurses();
        ~print_ncurses();
        int main_ncurses(void);
        int print_name(void);
    protected:
        bool _active;
};

void main_ncurses(void);
void print_name(void);