/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD16-jack.goodall
** File description:
** DomesticKoala
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction &koala) : _koala(koala)
{
}

DomesticKoala::~DomesticKoala()
{
}

const std::vector<methodPointer_t> *DomesticKoala::getActions() const
{
    std::vector<methodPointer_t> *tmp = new std::vector<methodPointer_t>;

    for (auto i = _actions.begin(); i != _actions.end(); ++i) {
        tmp->push_back(i->second);
    }
    return tmp;
}

void DomesticKoala::learnAction(unsigned char command, methodPointer_t action)
{
    _actions[command] = action;
}

void DomesticKoala::unlearnAction(unsigned char command)
{
    _actions.erase(command);
}

void DomesticKoala::doAction(unsigned char command, const std::string &param)
{
    if (_actions[command])
        (_koala.*_actions[command])(param);
}
