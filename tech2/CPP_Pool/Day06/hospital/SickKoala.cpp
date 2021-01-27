/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD06-jack.goodall
** File description:
** SickKoala
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name) : m_name(name)
{
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << m_name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::poke()
{
    std::cout << "Mr." << m_name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string drug)
{
    if (!drug.compare("Mars")) {
        std::cout << "Mr." << m_name << ": Mars, and it kreogs!" << std::endl;
        return true;
    } if (!drug.compare("Kinder")) {
        std::cout << "Mr." << m_name << ": There is a toy inside!" << std::endl;
        return true;
    }
    std::cout << "Mr." << m_name << ": Goerkreog!" << std::endl;
    return false;
}

void SickKoala::overDrive(std::string str)
{
    size_t pos = str.find("Kreog!");

    while (pos != std::string::npos) {
        str.erase(pos, 6);
        str.insert(pos, "1337!");
        pos = str.find("Kreog!");
    }
    std::cout << "Mr." << m_name << ": " << str << std::endl;
}

std::string SickKoala::getName()
{
    return m_name;
}
