/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-jack.goodall
** File description:
** GiftPaper
*/

#ifndef GIFTPAPER_HPP_
#define GIFTPAPER_HPP_

#include "Wrap.hpp"

class GiftPaper : public Wrap {
    public:
        GiftPaper();
        ~GiftPaper();

        void wrapMeThat(Object *object);

    protected:
    private:
};

#endif /* !GIFTPAPER_HPP_ */
