/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD08-jack.goodall
** File description:
** Carrier
*/

#include "Carrier.hpp"

Carrier::Carrier(const std::string id) : Id(id), Energy(300), Attack(100), Toughness(90), Speed(0)
{
    for (int i = 0; i < 5; i++)
        Droids[i] = nullptr;
}

Carrier::~Carrier()
{
    for (int i = 0; i < 5; i++)
        delete Droids[i];
}


Carrier &Carrier::operator<<(Droid *&droid)
{
    int i = 0;

    while (i < 5 && Droids[i] != nullptr) {
        if (Droids[i] == droid) return *this;
        i++;
    }
    if (i == 5) return *this;
    Droids[i] = droid;
    if (Speed) Speed -= 10;
    else Speed = 90;
    droid = nullptr;
    return *this;
}

Carrier &Carrier::operator>>(Droid *&droid)
{
    int i = 0;

    while (i < 5 && nullptr == Droids[i]) i++;
    if (i == 5) return *this;
    droid = Droids[i];
    Droids[i] = nullptr;
    Speed += 10;
    if (Speed == 100) Speed = 0;
    return *this;
}

Carrier &Carrier::operator<<(Carrier &carrier)
{
    size_t limit = (Energy + carrier.getEnergy() > 100) ? 100 - Energy : carrier.getEnergy();

    Energy += limit;
    carrier.setEnergy(carrier.getEnergy() - limit);
    return *this;
}

Carrier &Carrier::operator<<(size_t &energy)
{
    size_t limit = (Energy + energy > 100) ? 100 - Energy : energy;

    Energy += limit;
    energy -= limit;
    return *this;
}

Droid *&Carrier::operator[](const size_t idx)
{
    return Droids[idx];
}

int Carrier::getNbDroids() const
{
    int cnt = 0;

    for (int i = 0; i < 5; i++)
        cnt += ((Droids[i] != nullptr));
    return cnt;
}

Carrier &Carrier::operator~()
{
    int cnt = getNbDroids();

    if (cnt == 0)
        Speed = 0;
    else
        Speed = 90 - ((cnt - 1) * 10);
    return *this;
}

bool Carrier::operator()(const int x, const int y)
{
    size_t energy_needed = ((abs(x) + abs(y)) * (10 + (getNbDroids())));

    if (Energy < energy_needed || Speed == 0)
        return false;
    Energy -= energy_needed;
    return true;
}

std::ostream &operator<<(std::ostream &out, Carrier &carrier)
{
    out << "Carrier '" << carrier.getId() << "' Droid(s) on-board:" << std::endl;
    for (int i = 0; i < 5; i++) {
        out << "[" << i << "] : ";
        if (carrier[i] != nullptr)
            out << *carrier[i] << std::endl;
        else
            out << "Free" << std::endl;
    }
    out << "Speed : " << carrier.getSpeed() << ", Energy " << carrier.getEnergy();
    return (out);
}
