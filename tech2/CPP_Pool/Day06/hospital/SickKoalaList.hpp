/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD06-jack.goodall
** File description:
** SickKoalaList
*/

#ifndef SICKKOALALIST_HPP_
#define SICKKOALALIST_HPP_

#include "SickKoala.hpp"
#include <initializer_list>

class SickKoalaList {
    public:
        SickKoalaList(SickKoala *);
        ~SickKoalaList();
        bool isEnd();
        void append(SickKoalaList *);
        SickKoala *getFromName(std::string);
        SickKoalaList *remove(SickKoalaList *);
        SickKoalaList *removeFromName(std::string patient);
        SickKoala *getContent();
        SickKoalaList *getNext();
        void dump();
    private:
        SickKoala *m_value;
        SickKoalaList *m_next;
};

#endif /* !SICKKOALALIST_HPP_ */
