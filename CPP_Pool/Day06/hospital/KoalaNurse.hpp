/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD06-jack.goodall
** File description:
** KoalaNurse
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

#include "SickKoala.hpp"

class KoalaNurse {
    public:
        KoalaNurse(int id);
        ~KoalaNurse();
        void giveDrug(std::string, SickKoala *);
        std::string readReport(std::string);
        void timeCheck();
        int getID();
    protected:
    private:
        int m_id;
        bool m_working;
};

#endif /* !KOALANURSE_HPP_ */
