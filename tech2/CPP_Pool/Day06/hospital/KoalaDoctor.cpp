/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD06-jack.goodall
** File description:
** KoalaDoctor
*/

#include "KoalaDoctor.hpp"
#include <fstream>

KoalaDoctor::KoalaDoctor(std::string name) : m_name(name)
{
    std::cout << "Dr." << m_name << ": I'm Dr." << m_name
        << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
}

void KoalaDoctor::diagnose(SickKoala *patient)
{
    std::fstream report;
    const char *drugs[5] = {"Mars", "Kinder", "Crunch",
        "Maroilles", "Eucalyptus leaf"};

    std::cout << "Dr." << m_name << ": So what's goerking you Mr." <<
        patient->getName() << "?" << std::endl;
    patient->poke();
    report.open(patient->getName() + ".report", std::ios::out);
    if (!report) return;
    report << drugs[random() % 5];
    report.close();
}

void KoalaDoctor::timeCheck(void)
{
    if (!m_working) {
        std::cout << "Dr." << m_name <<
            ": Time to get to work!" << std::endl;
        m_working = true;
    } else {
        std::cout << "Dr." << m_name <<
            ": Time to go home to my eucalyptus forest!" << std::endl;
        m_working = false;
    }
}

std::string KoalaDoctor::getName()
{
    return m_name;
}
