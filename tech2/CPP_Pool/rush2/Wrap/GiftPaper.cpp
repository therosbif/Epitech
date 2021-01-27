/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-jack.goodall
** File description:
** GiftPaper
*/

#include "GiftPaper.hpp"

GiftPaper::GiftPaper() : Wrap("GiftPaper")
{
}

GiftPaper::~GiftPaper()
{
}

void GiftPaper::wrapMeThat(Object *object)
{
    if (_object == nullptr) {
        std::cout << "tuuuut tuuut tuut paper" << std::endl;
        _object = object;
        _open = false;
    } else
        std::cerr << "The Gift Paper already contains an object." << std::endl;
}
