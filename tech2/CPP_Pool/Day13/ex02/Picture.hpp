/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD13-jack.goodall
** File description:
** Picture
*/

#ifndef CPPD13_EX01_PICTURE_HPP_
#define CPPD13_EX01_PICTURE_HPP_

#include <iostream>
#include <fstream>

class Picture {
    public:
        Picture();
        Picture(const Picture &) = default;
        explicit Picture(const std::string &);
        ~Picture();
        Picture &operator=(const Picture &) = default;

        bool getPictureFromFile(const std::string &);

        std::string data;

    protected:
    private:
};

#endif /* !CPPD13_EX01_PICTURE_HPP_ */
