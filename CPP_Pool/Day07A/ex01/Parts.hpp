/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD07A-jack.goodall
** File description:
** Parts
*/

#ifndef PARTS_HPP_
#define PARTS_HPP_

#include <iostream>

class Arms {
    public:
        Arms(const std::string &serial = "A-01", bool functional = true);
        ~Arms();

        bool isFunctional() const;
        std::string serial() const;
        void informations() const;
    private:
        std::string _serial;
        bool _functional;
};

class Legs {
    public:
        Legs(const std::string &serial = "L-01", bool functional = true);
        ~Legs();

        bool isFunctional() const;
        std::string serial() const;
        void informations() const;
    private:
        std::string _serial;
        bool _functional;
};

class Head {
    public:
        Head(const std::string &serial = "H-01", bool functional = true);
        ~Head();

        bool isFunctional() const;
        std::string serial() const;
        void informations() const;
    private:
        std::string _serial;
        bool _functional;
};

#endif /* !PARTS_HPP_ */
