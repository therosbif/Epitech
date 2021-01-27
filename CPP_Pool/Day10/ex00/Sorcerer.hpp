/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** Sorcerer
*/

#ifndef SORCERER_HPP_
#define SORCERER_HPP_

#include <iostream>
#include <string>
#include "Peon.hpp"

class Sorcerer {
    public:
        Sorcerer(const std::string &name, const std::string &title);
        ~Sorcerer();

        const std::string &getName() const { return _name; };
        const std::string &getTitle() const { return _title; };

        void polymorph(const Victim &victim) const;

    protected:
    private:
        const std::string &_name;
        const std::string &_title;
};

std::ostream &operator<< (std::ostream &, const Sorcerer &);

#endif /* !SORCERER_HPP_ */
