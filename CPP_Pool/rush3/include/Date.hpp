/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-jack.goodall [WSL: Ubuntu-20.04]
** File description:
** Date
*/

#pragma once

#include <ctime>
#include <iostream>

#include "IMonitorModule.hpp"

class Date : public IMonitorModule {
    public:
        Date();
        ~Date();

        void refreshInfo();

        void setActive(bool active) { _active = active; }
        void setPosition(unsigned int position) { _position = position; }

        bool getActive() const { return _active; }
        unsigned int getPosition() const { return _position; }

        std::string getDay() const { return (_day); }
        std::string getMonth() const { return (_month); }
        std::string getYear() const { return (_year); }
        std::string getHour() const { return (_hour); }
        std::string getMin() const { return (_min); }
        std::string getSec() const { return (_sec); }
    protected:
    private:
        std::string _day;
        std::string _month;
        std::string _year;

        std::string _hour;
        std::string _min;
        std::string _sec;

        bool _active;
        unsigned int _position;
};
