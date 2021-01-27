/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD17-jack.goodall
** File description:
** OneTime
*/

#ifndef ONETIME_HPP_
#define ONETIME_HPP_

#include "IEncryptionMethod.hpp"
#include <string>
#include <iostream>

class OneTime : public IEncryptionMethod {
    public:
        OneTime(const std::string &key);
        ~OneTime() = default;

        void encryptChar(char c);
        void decryptChar(char c);
        void reset() { _idx = 0; };

    protected:
    private:
        std::string _key;
        int _idx;
};

#endif /* !ONETIME_HPP_ */
