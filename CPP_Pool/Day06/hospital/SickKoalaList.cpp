/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD06-jack.goodall
** File description:
** SickKoalaList
*/

#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *patient) : m_value(patient), m_next(nullptr)
{
}

SickKoalaList::~SickKoalaList()
{
}

bool SickKoalaList::isEnd()
{
    return (m_next == nullptr);
}

void SickKoalaList::append(SickKoalaList *patient)
{
    SickKoalaList *tmp = this;

    if (tmp->m_value == nullptr)
        this->m_value = patient->m_value;
    for (; !tmp->isEnd(); tmp = tmp->m_next);
    tmp->m_next = patient;
}

SickKoala *SickKoalaList::getFromName(std::string patient)
{
    SickKoalaList *tmp = this;

    for (; tmp; tmp = tmp->m_next) {
        if (!patient.compare(tmp->m_value->getName()))
            return tmp->m_value;
    }
    return nullptr;
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *node)
{
    SickKoalaList *tmp = this;

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

SickKoalaList *SickKoalaList::removeFromName(std::string patient)
{
    SickKoalaList *tmp = this;

    if (patient == tmp->m_value->getName())
        return tmp->m_next;
    for (; tmp; tmp = tmp->m_next) {
        if (patient == tmp->m_next->m_value->getName()) {
            tmp->m_next = tmp->m_next->m_next;
            return this;
        }
    }
    return this;
}

SickKoala *SickKoalaList::getContent(void)
{
    return m_value;
}

SickKoalaList *SickKoalaList::getNext(void)
{
    return m_next;
}

void SickKoalaList::dump(void)
{
    SickKoalaList *tmp = this;

    std::cout << "Patients: ";
    for (; tmp; tmp = tmp->m_next) {
        if (tmp->m_value != nullptr)
            std::cout << tmp->m_value->getName();
        else
            std::cout << "[nullptr]";
        if (!tmp->isEnd())
            std::cout << ", ";
    }
    std::cout << '.' << std::endl;
}
