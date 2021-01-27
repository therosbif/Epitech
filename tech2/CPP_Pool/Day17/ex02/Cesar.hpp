/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD17-jack.goodall
** File description:
** Cesar
*/

#ifndef CESAR_HPP_
#define CESAR_HPP_

#include "IEncryptionMethod.hpp"
#include <iostream>

class Cesar : public IEncryptionMethod {
    public:
        Cesar() = default;
        ~Cesar() = default;

    void encryptChar(char c);
    void decryptChar(char c);
    void reset() { _key = 0; };

    protected:
    private:
        int _key;
};

#endif /* !CESAR_HPP_ */
