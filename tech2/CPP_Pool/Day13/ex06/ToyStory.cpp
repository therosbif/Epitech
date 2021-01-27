/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD13-jack.goodall
** File description:
** ToyStory
*/

#include "ToyStory.hpp"

ToyStory::ToyStory()
{
}

ToyStory::~ToyStory()
{
}

static bool my_turn(Toy &toy, bool ((Toy::*func)(const std::string &)), std::string &line, bool *turn)
{
    Toy::Error err;

    if (!line.compare(0, 8, "picture:")) {
        *turn = !(*turn);
        if (!toy.setAscii(line.substr(8, line.length() - 8))) {
            err = toy.getLastError();
            std::cout << err.where() << ": " << err.what() << std::endl;
            return true;
        } else std::cout << toy.getAscii() << std::endl;
    } else (toy.*func)(line);
    return false;
}

void ToyStory::tellMeAStory(const std::string &path, Toy &toy1,
    bool ((Toy::*func1)(const std::string &)), Toy &toy2, bool ((Toy::*func2)(const std::string &)))
{
    bool turn = false;
    std::string line;
    std::fstream file;

    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;

    file.open(path, std::ios::in);
    if (!file) {
        std::cout << "Bad Story" << std::endl;
        return;
    }
    while (std::getline(file, line)) {
        if (!turn) {
            if (my_turn(toy1, func1, line, &turn)) break;
        } else {
            if (my_turn(toy2, func2, line, &turn)) break;
        }
        turn = !turn;
    }
    file.close();
}
