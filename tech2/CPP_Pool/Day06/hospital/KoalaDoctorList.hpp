/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD06-jack.goodall
** File description:
** KoalaDoctorList
*/

#ifndef KOALADOCTORLIST_HPP_
#define KOALADOCTORLIST_HPP_

#include "KoalaDoctor.hpp"

class KoalaDoctorList {
    public:
        KoalaDoctorList(KoalaDoctor *);
        ~KoalaDoctorList();
        bool isEnd();
        void append(KoalaDoctorList *);
        KoalaDoctor *getFromName(std::string);
        KoalaDoctorList *remove(KoalaDoctorList *);
        KoalaDoctorList *removeFromName(std::string);
        KoalaDoctor *getContent();
        KoalaDoctorList *getNext();
        void dump();
    private:
        KoalaDoctor *m_value;
        KoalaDoctorList *m_next;
};

#endif /* !KOALADOCTORLIST_HPP_ */
