/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD06-jack.goodall
** File description:
** main
*/

#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
    std::fstream file;
    std::string line;

    if (argc < 2)
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
    for (int i = 1; i < argc; i++) {
        file.open(argv[i], std::ios::in);
        if (!file) {
            std::cerr << "my_cat: " << argv[i] << ": No such file or directory" << std::endl;
            continue;
        }
        while (std::getline(file, line)) {
            std::cout << line;
            if (!file.eof())
                std::cout << std::endl;
        }
        file.close();
    }
    return 0;
}
