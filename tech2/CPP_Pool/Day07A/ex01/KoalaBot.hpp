/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD07A-jack.goodall
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_

#include "Parts.hpp"

class KoalaBot {
    public:
        KoalaBot(const std::string &serial = "Bob-01");
        ~KoalaBot();

        void setParts(Arms const &);
        void setParts(Legs const &);
        void setParts(Head const &);
        void swapParts(Arms &);
        void swapParts(Legs &);
        void swapParts(Head &);
        void informations() const;
        bool status() const;
    private:
        std::string _serial;
        Arms _arms;
        Legs _legs;
        Head _head;
};

#endif /* !KOALABOT_HPP_ */
