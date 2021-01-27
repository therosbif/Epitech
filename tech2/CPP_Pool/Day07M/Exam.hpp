/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD07M-jack.goodall
** File description:
** Exam
*/

#ifndef EXAM_HPP_
#define EXAM_HPP_

#include <iostream>

bool _cheat = false;

class Exam {
    public:
        Exam(bool Exam::*) : _cheatPtr(false) { std::cout << "[The exam is starting]" << std::endl; };

        bool isCheating(void) { return _cheat; };

        void start(int);
        void (Exam::*kobayashiMaru)(int);

        bool cheat;
        bool *operator=(bool c) {
            _cheat = c;
        }
    private:
        bool _cheatPtr
};

#endif /* !EXAM_HPP_ */
