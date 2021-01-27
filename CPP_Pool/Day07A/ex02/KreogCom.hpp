/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD07A-jack.goodall
** File description:
** KreogCom
*/

#ifndef KREOGCOM_HPP_
#define KREOGCOM_HPP_

#include <iostream>

class KreogCom {
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom();

        void addCom(int x, int y, int serial);
        void removeCom();
        KreogCom *getCom();

        void ping() const;
        void locateSquad() const;
    private:
        int m_x;
        int m_y;
        const int m_serial;
        KreogCom *m_next;
};

#endif /* !KREOGCOM_HPP_ */
