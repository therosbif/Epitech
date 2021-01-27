/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** Peon
*/

#ifndef PEON_HPP_
#define PEON_HPP_

#include "Victim.hpp"

class Peon : public Victim {
    public:
        Peon(const std::string &);
        ~Peon();

        void getPolymorphed() const;

    protected:
    private:
};

#endif /* !PEON_HPP_ */
