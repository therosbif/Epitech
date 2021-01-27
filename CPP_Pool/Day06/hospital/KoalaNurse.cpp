/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD06-jack.goodall
** File description:
** KoalaNurse
*/

#include <fstream>
#include "KoalaNurse.hpp"
#include <iostream>

KoalaNurse::KoalaNurse(int id) : m_id(id), m_working(false)
{
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << m_id << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
    patient->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string file)
{
    size_t pos = file.find(".report");
    std::string patient = file.substr(0, pos);
    std::string drug;
    std::fstream my_file;

    my_file.open(file, std::ios::in);
    if (!my_file)
        return std::string("");
    if (!std::getline(my_file, drug)) {
        my_file.close();
        return std::string("");
    }
    my_file.close();
    std::cout << "Nurse " << m_id << ": Kreog! Mr." << patient
        << " needs a " << drug << "!" << std::endl;
    return drug;
}

void KoalaNurse::timeCheck(void)
{
    if (m_working) {
        std::cout << "Nurse " << m_id <<
            ": Time to go home to my eucalyptus forest!" << std::endl;
        m_working = false;
    } else {
        std::cout << "Nurse " << m_id <<
            ": Time to get to work!" << std::endl;
        m_working = true;
    }
}

int KoalaNurse::getID()
{
    return m_id;
}
