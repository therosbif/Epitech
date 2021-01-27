/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD13-jack.goodall
** File description:
** Toy
*/

#ifndef CPPD13_EX02_TOY_HPP_
#define CPPD13_EX02_TOY_HPP_

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
        bool setAscii(const std::string &file);

        Toy &operator<<(const std::string &);

        virtual void speak(const std::string &);
        virtual bool speak_es(const std::string &);

        typedef enum ToyType_e { BASIC_TOY, ALIEN, BUZZ, WOODY } ToyType;

        class Error {
            public:
                const std::string what() const;
                const std::string where() const;
                int type;
                typedef enum ErrorType_e { UNKNOWN, PICTURE, SPEAK } ErrorType;
        };

        Error getLastError() const { return _err; };

    protected:
    private:
        Picture _picture;
        int _type;
        std::string _name;
        Error _err;
};

std::ostream &operator<<(std::ostream &out, const Toy &toy);

#endif /* !CPPD13_EX02_TOY_HPP_ */
