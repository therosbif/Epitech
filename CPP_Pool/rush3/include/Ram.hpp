/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-jack.goodall
** File description:
** Ram
*/

#ifndef RAM_HPP_
#define RAM_HPP_

#include "IMonitorModule.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>

class Ram : public IMonitorModule {
    public:
        Ram();
        ~Ram() = default;

        void refreshInfo();

        void setActive(bool active) { _active = active; }
        void setPosition(unsigned int position) { _position = position; }

        bool getActive() const { return _active; }
        unsigned int getPosition() const { return _position; }

        unsigned long long int getTotalMem() const { return _memtotal; };
        unsigned long long int getAvailMem() const { return _memavail; };
        unsigned long long int getFreeMem() const { return _memfree; };
        unsigned long long int getUsedMem() const { return _memused; };

        unsigned long long int getTotalSwap() const { return _swaptotal; };
        unsigned long long int getFreeSwap() const { return _swapfree; };
        unsigned long long int getUsedSwap() const { return _swapused; };

        float getMem() const { return _mem_perc; };
        float getSwap() const { return _swap_perc; };

    protected:
    private:
        unsigned long long int _memtotal;
        unsigned long long int _memavail;
        unsigned long long int _memfree;
        unsigned long long int _memused;

        unsigned long long int _swaptotal;
        unsigned long long int _swapfree;
        unsigned long long int _swapused;

        float _mem_perc;
        float _swap_perc;

        bool _active;
        unsigned int _position;
};

#endif /* !RAM_HPP_ */
