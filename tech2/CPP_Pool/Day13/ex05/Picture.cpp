/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD13-jack.goodall
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture() : data("")
{
}

Picture::Picture(const std::string &path)
{
    getPictureFromFile(path);
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &path)
{
    std::fstream file;
    std::string line;

    file.open(path, std::ios::in);
    if (!file) {
        data = "ERROR";
        return false;
    }
    data.assign("");
    while (std::getline(file, line)) {
        data.append(line);
        if (!file.eof()) data.append("\n");
    }
    file.close();
    return true;
}
