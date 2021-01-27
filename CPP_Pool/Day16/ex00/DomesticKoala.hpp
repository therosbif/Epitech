/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD16-jack.goodall
** File description:
** DomesticKoala
*/

#ifndef DOMESTICKOALA_HPP_
#define DOMESTICKOALA_HPP_

#include <string>
#include <vector>
#include <unordered_map>
#include "KoalaAction.hpp"

using methodPointer_t = void (KoalaAction::*)(const std::string &);

class DomesticKoala {
    public:
        DomesticKoala(KoalaAction &);
        ~DomesticKoala();
        DomesticKoala(const DomesticKoala &) = default;
        DomesticKoala &operator=(const DomesticKoala &) = default;

        const std::vector<methodPointer_t> *getActions() const;
        void learnAction(unsigned char command, methodPointer_t action);
        void unlearnAction(unsigned char command);
        void doAction(unsigned char command, const std::string &param);
        void setKoalaAction(KoalaAction &);

    protected:
    private:
        KoalaAction _koala;
        std::unordered_map<unsigned char, methodPointer_t> _actions;
};

#endif /* !DOMESTICKOALA_HPP_ */
