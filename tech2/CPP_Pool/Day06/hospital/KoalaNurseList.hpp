/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD06-jack.goodall
** File description:
** KoalaNurseList
*/

#ifndef KOALANURSELIST_HPP_
#define KOALANURSELIST_HPP_

#include "KoalaNurse.hpp"

class KoalaNurseList {
    public:
        KoalaNurseList(KoalaNurse *);
        ~KoalaNurseList();
        bool isEnd();
        void append(KoalaNurseList *);
        KoalaNurse *getFromID(int);
        KoalaNurseList *remove(KoalaNurseList *);
        KoalaNurseList *removeFromID(int);
        KoalaNurse *getContent();
        KoalaNurseList *getNext();
        void dump();
    private:
        KoalaNurse *m_value;
        KoalaNurseList *m_next;
};

#endif /* !KOALANURSELIST_HPP_ */
