/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD17-jack.goodall
** File description:
** Encryption
*/

#ifndef ENCRYPTION_HPP_
#define ENCRYPTION_HPP_

#include "Cesar.hpp"
#include "OneTime.hpp"
#include <algorithm>

using encryptPtr_t = void (IEncryptionMethod::*)(char);

class Encryption {
    public:
        Encryption(IEncryptionMethod &, encryptPtr_t);
        ~Encryption() = default;

        void operator()(const char) const;

        static void encryptString(IEncryptionMethod &method, const std::string &e);
        static void decryptString(IEncryptionMethod &method, const std::string &e);

    protected:
    private:
        IEncryptionMethod *_method;
        encryptPtr_t _ptr;
};

#endif /* !ENCRYPTION_HPP_ */
