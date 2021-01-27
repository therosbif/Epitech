/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD16-jack.goodall
** File description:
** BF_Translator
*/

#ifndef BF_TRANSLATOR_HPP_
#define BF_TRANSLATOR_HPP_

#include <string>
#include <fstream>
#include <unordered_map>

class BF_Translator {
    public:
        BF_Translator();

        int translate(const std::string &in, const std::string &out);

    protected:
    private:
        std::unordered_map<char, std::string> _instructions;
};

#endif /* !BF_TRANSLATOR_HPP_ */
