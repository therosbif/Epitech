/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD06-jack.goodall
** File description:
** SickKoala
*/

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_

#include <iostream>
#include <string>

class SickKoala {
    public:
        SickKoala(std::string);
        ~SickKoala();
        void poke();
        bool takeDrug(std::string);
        void overDrive(std::string);
        std::string getName();
    protected:
    private:
        std::string m_name;
};

#endif /* !SICKKOALA_HPP_ */
