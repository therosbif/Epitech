/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD13-jack.goodall
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody : public Toy {
    public:
        Woody(const std::string &name, const std::string &file = "./woody.txt");
        Woody(const Woody &) = default;
        ~Woody();
        Woody &operator=(const Woody &) = default;

        void speak(const std::string &);

    protected:
    private:
};

#endif /* !WOODY_HPP_ */
