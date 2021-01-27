/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD06-jack.goodall
** File description:
** KoalaDoctorList
*/

#include "KoalaDoctorList.hpp"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *doctor) : m_value(doctor), m_next(nullptr)
{
}

KoalaDoctorList::~KoalaDoctorList()
{
}

bool KoalaDoctorList::isEnd()
{
    return (m_next == nullptr);
}

void KoalaDoctorList::append(KoalaDoctorList *doctor)
{
    KoalaDoctorList *tmp = this;

    if (tmp->m_value == nullptr)
        this->m_value = doctor->m_value;
    for (; !tmp->isEnd(); tmp = tmp->m_next);
    tmp->m_next = doctor;
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string doctor)
{
    KoalaDoctorList *tmp = this;

    for (; tmp; tmp = tmp->m_next) {
        if (doctor == tmp->m_value->getName())
            return tmp->m_value;
    }
    return nullptr;
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *node)
{
    KoalaDoctorList *tmp = this;

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

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string doctor)
{
    KoalaDoctorList *tmp = this;

    if (doctor == tmp->m_value->getName())
        return tmp->m_next;
    for (; tmp; tmp = tmp->m_next) {
        if (doctor == tmp->m_next->m_value->getName()) {
            tmp->m_next = tmp->m_next->m_next;
            return this;
        }
    }
    return this;
}

void KoalaDoctorList::dump(void)
{
    KoalaDoctorList *tmp = this;

    std::cout << "Doctors: ";
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

KoalaDoctor *KoalaDoctorList::getContent(void)
{
    return m_value;
}

KoalaDoctorList *KoalaDoctorList::getNext(void)
{
    return m_next;
}
