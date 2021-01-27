/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD17-jack.goodall
** File description:
** Encryption
*/

#include "Encryption.hpp"

Encryption::Encryption(IEncryptionMethod &method, encryptPtr_t ptr) : _method(&method), _ptr(ptr)
{
}

void Encryption::operator()(char c) const
{
    (*_method.*_ptr)(c);
}

void Encryption::encryptString(IEncryptionMethod &method, const std::string &e)
{
    method.reset();
    for_each(e.begin(), e.end(), [&method](char c) { method.encryptChar(c); });
    std::cout << std::endl;
}

void Encryption::decryptString(IEncryptionMethod &method, const std::string &e)
{
    method.reset();
    for_each(e.begin(), e.end(), [&method](char c) { method.decryptChar(c); });
    std::cout << std::endl;
}
