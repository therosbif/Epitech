/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD08-jack.goodall
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory() : Exp(0), Fingerprint(random())
{
}

DroidMemory::~DroidMemory()
{
}

DroidMemory &DroidMemory::operator<<(const DroidMemory &memory)
{
    Exp += memory.getExp();
    Fingerprint ^= memory.getFingerprint();
    return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &memory) const
{
    memory.setExp(memory.getExp() + Exp);
    memory.setFingerprint(memory.getFingerprint() ^ Fingerprint);
    return memory;
}

DroidMemory &DroidMemory::operator+=(const size_t exp)
{
    Exp += exp;
    Fingerprint ^= exp;
    return *this;
}

DroidMemory DroidMemory::operator+(const DroidMemory &memory) const
{
    DroidMemory new_mem ;

    new_mem.setExp(memory.getExp() + Exp);
    new_mem.setFingerprint(memory.getFingerprint() ^ Fingerprint);
    return new_mem;
}

DroidMemory DroidMemory::operator+(const size_t exp) const
{
    DroidMemory new_mem;

    new_mem.setExp(exp + Exp);
    new_mem.setFingerprint(exp ^ Fingerprint);
    return new_mem;
}

std::ostream &operator << (std::ostream &out, const DroidMemory &droidmem)
{
    out << "DroidMemory '" << droidmem.getFingerprint() << "', " << droidmem.getExp();
    return (out);
}
