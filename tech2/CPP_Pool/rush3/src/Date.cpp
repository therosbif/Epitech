/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-jack.goodall [WSL: Ubuntu-20.04]
** File description:
** Date
*/

#include "Date.hpp"

Date::Date()
{
    refreshInfo();

    _active = 0;
    _position = 0;
}

Date::~Date()
{
}

void Date::refreshInfo()
{
    std::time_t time_type = std::time(nullptr);
    std::tm *now = std::localtime(&time_type);

    _year = std::to_string(1900 + now->tm_year);
    _month = std::to_string(1 + now->tm_mon);
    _day = std::to_string(now->tm_mday);

    _hour = std::to_string(now->tm_hour);
    _min = std::to_string(now->tm_min);
    _sec = std::to_string(now->tm_sec);
}
