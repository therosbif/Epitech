/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD06-jack.goodall
** File description:
** main
*/

#include <iostream>
#include <iomanip>

int main(void)
{
    std::string input;
    double temp;
    size_t len;

    if (!std::getline(std::cin, input))
        return 84;
    len = input.find(' ');
    temp = std::stod(input.substr(0, len));
    if (input.find("Celsius", 0) != std::string::npos)
        std::cout << std::setw(16) << std::fixed << std::setprecision(3)
        << (((9.0 * temp) / 5.0) + 32) << std::setw(16) << "Fahrenheit"
        << std::endl;
    if (input.find("Fahrenheit", 0) != std::string::npos)
        std::cout << std::setw(16) << std::fixed << std::setprecision(3)
        << (5.0 / 9.0 * (temp - 32)) << std::setw(16) << "Celsius"
        << std::endl;
    return 0;
}
