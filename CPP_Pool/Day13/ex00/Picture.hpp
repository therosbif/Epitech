/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD13-jack.goodall
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <iostream>
#include <fstream>

class Picture {
    public:
        Picture();
        Picture(const std::string &);
        ~Picture();

        bool getPictureFromFile(const std::string &);

        std::string data;

    protected:
    private:
};

#endif /* !PICTURE_HPP_ */
