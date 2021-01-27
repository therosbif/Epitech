/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-jack.goodall
** File description:
** Box
*/

#ifndef BOX_HPP_
#define BOX_HPP_

#include "Wrap.hpp"

class Box : public Wrap {
    public:
        Box();
        ~Box();

        void wrapMeThat(Object *object);

    protected:
    private:
};

#endif /* !BOX_HPP_ */
