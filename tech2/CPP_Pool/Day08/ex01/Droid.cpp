/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD08-jack.goodall
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string id) : Id(id), Energy(50), Attack(25), Toughness(15)
{
    Status = new std::string("Standing by");
    BattleData = new DroidMemory();
    std::cout << "Droid '" << Id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &droid) : Attack(droid.getAttack()), Toughness(droid.getToughness())
{
    Id = droid.getId();
    Energy = droid.getEnergy();
    Status = droid.getStatus();
    BattleData = droid.getBattleData();
    std::cout << "Droid '" << Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    delete Status;
    delete BattleData;
    std::cout << "Droid '" << Id << "' Destroyed" << std::endl;
}


bool Droid::operator == (const Droid &droid) const
{
    return (*Status == *droid.getStatus());
}

bool Droid::operator != (const Droid &droid) const
{
    return !(*Status == *droid.getStatus());
}

Droid &Droid::operator << (size_t &energy)
{
    size_t limit = (Energy + energy > 100) ? 100 - Energy : energy;

    Energy += limit;
    energy -= limit;
    return *this;
}

Droid &Droid::operator = (const Droid &droid)
{
    this->setId(droid.getId());
    this->setEnergy(droid.getEnergy());
    this->setStatus(droid.getStatus());
    this->setBattleData(droid.getBattleData());
    return *this;
}

std::ostream &operator << (std::ostream &out, const Droid &droid)
{
    out << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", " << droid.getEnergy();
    return (out);
}
