/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD13-jack.goodall
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy() : _picture(new Picture()), _type(BASIC_TOY), _name("toy")
{
}

Toy::Toy(int toyType, const std::string &name, const std::string &file) : _picture(new Picture(file)), _type(toyType), _name(name)
{
}

Toy::~Toy()
{
}

bool Toy::setAscii(const std::string &file)
{

    if (_picture->getPictureFromFile(file)) {
        return true;
    } else {
        _err.type = Error::PICTURE;
        return false;
    }
}

bool Toy::speak(const std::string &text)
{
    std::cout << _name << " \"" << text << "\"" << std::endl;
    return true;
}

bool Toy::speak_es(const std::string &)
{
    _err.type = Error::SPEAK;
    return false;
}


Toy &Toy::operator<<(const std::string &text)
{
    _picture->data = text;
    return *this;
}


std::ostream &operator<<(std::ostream &out, const Toy &toy)
{
    out << toy.getName() << std::endl;
    out << toy.getAscii() << std::endl;
    return out;
}

const std::string Toy::Error::what() const
{
    const std::string empty = "";
    const std::string pic = "bad new illustration";
    const std::string speakes = "wrong mode";

    switch (type) {
        case UNKNOWN: return empty;
        case PICTURE: return pic;
        case SPEAK: return speakes;
        default: return empty;
    }
}

const std::string Toy::Error::where() const
{
    const std::string empty = "";
    const std::string pic = "setAscii";
    const std::string speakes = "speak_es";

    switch (type) {
        case UNKNOWN: return empty;
        case PICTURE: return pic;
        case SPEAK: return speakes;
        default: return empty;
    }
}
