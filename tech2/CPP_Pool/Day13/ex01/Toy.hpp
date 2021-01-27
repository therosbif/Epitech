/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD13-jack.goodall
** File description:
** Toy
*/

#ifndef CPPD13_EX01_TOY_HPP_
#define CPPD13_EX01_TOY_HPP_

#include "Picture.hpp"

class Toy {
    public:
        Toy();
        Toy(const Toy &) = default;
        Toy(int toyType, const std::string &name, const std::string &file);
        ~Toy();
        Toy &operator=(const Toy &) = default;

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

#endif /* !CPPD13_EX01_TOY_HPP_ */
