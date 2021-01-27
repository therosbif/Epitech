/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD13-jack.goodall
** File description:
** ToyStory
*/

#ifndef TOYSTORY_HPP_
#define TOYSTORY_HPP_

#include "Toy.hpp"

class ToyStory {
    public:
        ToyStory();
        ~ToyStory();

        static void tellMeAStory(const std::string &, Toy &, bool ((Toy::*)(const std::string &)), Toy &, bool ((Toy::*)(const std::string &)));

    protected:
    private:
};

#endif /* !TOYSTORY_HPP_ */
