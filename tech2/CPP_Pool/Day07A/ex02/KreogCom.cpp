/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD07A-jack.goodall
** File description:
** KreogCom
*/

#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial) : m_x(x), m_y(y), m_serial(serial), m_next(nullptr)
{
    std::cout << "KreogCom " << serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *tmp = m_next;

    m_next = new KreogCom(x, y, serial);
    m_next->m_next = tmp;
}

KreogCom *KreogCom::getCom()
{
    return m_next;
}

void KreogCom::removeCom()
{
    KreogCom *tmp = m_next;

    m_next = m_next->m_next;
    delete tmp;
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << m_serial << " currently at " << m_x << " " << m_y << std::endl;
}

void KreogCom::locateSquad() const
{
    KreogCom *tmp = m_next;

    for (; tmp; tmp = tmp->m_next)
        tmp->ping();
    this->ping();
}
