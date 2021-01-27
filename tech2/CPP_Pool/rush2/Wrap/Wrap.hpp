/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-jack.goodall
** File description:
** Wrap
*/

#ifndef WRAP_HPP_
#define WRAP_HPP_

#include <iostream>
#include "../Toys/Object.hpp"

class Wrap : public Object {
    public:
        Wrap(const std::string &type);
        ~Wrap();

        virtual void wrapMeThat(Object *object) = 0;

        Wrap *openMe() { _open = true; return this;};
        Wrap *closeMe() { _open = false;  return this;};

        Object *takeObject();

        Wrap *isTaken();

        std::string xml() final;

    protected:
        bool _open;
        Object *_object;
    private:
};

#endif /* !WRAP_HPP_ */
