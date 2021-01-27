/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** Victim
*/

#ifndef VICTIM_HPP_
#define VICTIM_HPP_

#include <iostream>
#include <string>

class Victim {
    public:
        Victim(const std::string &);
        virtual ~Victim();

        const std::string &getName() const { return _name; };

        virtual void getPolymorphed() const;

    protected:
        const std::string &_name;
    private:
};

std::ostream &operator<< (std::ostream &, const Victim &);

#endif /* !VICTIM_HPP_ */
