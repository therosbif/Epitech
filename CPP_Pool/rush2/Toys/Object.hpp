/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-jack.goodall
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>
#include <string>

class Object {
    public:
        Object(const std::string &title, const std::string &type);
        virtual ~Object();

        const std::string getTitle() const { return _title; };
        const std::string getType() const { return _type; };
        bool getTaken() const { return _taken; };

        virtual Object *isTaken() = 0;

        virtual std::string xml() = 0;

    protected:
        bool _taken;
    private:
        const std::string _title;
        const std::string _type;
};

std::ostream &operator<<(std::ostream &out, const Object &object);

#endif /* !OBJECT_HPP_ */
