/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD08-jack.goodall
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <iostream>

class DroidMemory {
    public:
        DroidMemory();
        ~DroidMemory();

        size_t getFingerprint() const { return Fingerprint; };
        size_t getExp() const { return Exp; };

        void setFingerprint(size_t fingerprint) { Fingerprint = fingerprint; };
        void setExp(size_t exp) { Exp = exp; };

        DroidMemory &operator<<(const DroidMemory &memory);
        DroidMemory &operator>>(DroidMemory &memory) const;

        DroidMemory &operator+=(const DroidMemory &memory) { return (*this << memory); };
        DroidMemory &operator+=(const size_t);

        DroidMemory operator+(const DroidMemory &) const;
        DroidMemory operator+(const size_t) const;

    protected:
    private:
        size_t Exp;
        size_t Fingerprint;
};

std::ostream &operator<< (std::ostream &, const DroidMemory &);

#endif /* !DROIDMEMORY_HPP_ */
