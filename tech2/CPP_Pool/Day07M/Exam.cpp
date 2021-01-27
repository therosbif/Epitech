/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD07M-jack.goodall
** File description:
** Exam
*/

#include "Exam.hpp"

void Exam::start(int ships)
    {
        std::cout << ships << "Klingon vessels appeared out of nowhere." << std::endl
            << "they are fully armed and shielded" << std::endl;
        if (!_cheat)
            std::cout << "This exam is hard... you lost again.";
        else
            std::cout << "What the... someone changed the parameters of the exam !" << std::endl;
    }
