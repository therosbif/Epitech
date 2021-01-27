/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD13-jack.goodall
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy {
    public:
        Buzz(const std::string &name, const std::string &file = "./buzz.txt");
        Buzz(const Buzz &buzz);
        ~Buzz();
        Buzz &operator=(const Buzz &buzz);

        void speak(const std::string &);

    protected:
    private:
};

#endif /* !BUZZ_HPP_ */
