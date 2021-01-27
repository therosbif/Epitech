/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD06-jack.goodall
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include "KoalaNurse.hpp"
#include <string>

class KoalaDoctor {
    public:
        KoalaDoctor(std::string);
        ~KoalaDoctor();
        void diagnose(SickKoala *);
        void timeCheck();
        std::string getName();
    protected:
    private:
        std::string m_name;
        std::string m_patient_name;
        bool m_working;
};

#endif /* !KOALADOCTOR_HPP_ */
