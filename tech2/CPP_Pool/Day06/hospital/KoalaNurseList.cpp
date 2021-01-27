/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD06-jack.goodall
** File description:
** KoalaNurseList
*/

#include "KoalaNurseList.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *nurse) : m_value(nurse), m_next(nullptr)
{
}

KoalaNurseList::~KoalaNurseList()
{
}

bool KoalaNurseList::isEnd()
{
    return (m_next == nullptr);
}

void KoalaNurseList::append(KoalaNurseList *nurse)
{
    KoalaNurseList *tmp = this;

    if (tmp->m_value == nullptr)
        this->m_value = nurse->m_value;
    for (; !tmp->isEnd(); tmp = tmp->m_next);
    tmp->m_next = nurse;
}

KoalaNurse *KoalaNurseList::getFromID(int nurse)
{
    KoalaNurseList *tmp = this;

    for (; tmp; tmp = tmp->m_next) {
        if (nurse == tmp->m_value->getID())
            return tmp->m_value;
    }
    return nullptr;
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *node)
{
    KoalaNurseList *tmp = this;

    if (!node) return this;
    if (tmp == node) return tmp->m_next;
    for (; tmp; tmp = tmp->m_next) {
        if (node == tmp->m_next) {
            tmp->m_next = tmp->m_next->m_next;
            return this;
        }
    }
    return this;
}

KoalaNurseList *KoalaNurseList::removeFromID(int nurse)
{
    KoalaNurseList *tmp = this;

    if (nurse == tmp->m_value->getID())
        return tmp->m_next;
    for (; tmp; tmp = tmp->m_next) {
        if (nurse == tmp->m_next->m_value->getID()) {
            tmp->m_next = tmp->m_next->m_next;
            return this;
        }
    }
    return this;
}

void KoalaNurseList::dump(void)
{
    KoalaNurseList *tmp = this;

    std::cout << "Nurses: ";
    for (; tmp; tmp = tmp->m_next) {
        if (tmp->m_value != nullptr)
            std::cout << tmp->m_value->getID();
        else
            std::cout << "[nullptr]";
        if (!tmp->isEnd())
            std::cout << ", ";
    }
    std::cout << '.' << std::endl;
}

KoalaNurse *KoalaNurseList::getContent(void)
{
    return m_value;
}

KoalaNurseList *KoalaNurseList::getNext(void)
{
    return m_next;
}
