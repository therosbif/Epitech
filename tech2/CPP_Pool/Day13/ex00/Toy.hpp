/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD13-jack.goodall
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <iostream>
#include "Picture.hpp"

class Toy {
    public:
        Toy();
        Toy(int toyType, const std::string &name, const std::string &file);
        ~Toy();

        int getType() const { return _type; };
        const std::string &getName() const { return _name; };
        const std::string &getAscii() const { return _picture.data; };

        void setName(const std::string &name) { _name = name; };
        bool setAscii(const std::string &file) { return _picture.getPictureFromFile(file); };

        typedef enum ToyType_e { BASIC_TOY, ALIEN } ToyType;

    protected:
    private:
        Picture _picture;
        int _type;
        std::string _name;
};

#endif /* !TOY_HPP_ */
