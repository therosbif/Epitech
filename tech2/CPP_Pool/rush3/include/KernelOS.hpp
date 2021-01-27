/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-jack.goodall [WSL: Ubuntu-20.04]
** File description:
** KernelOS
*/

#pragma once

#include <iostream>
#include <sys/utsname.h>

#include "IMonitorModule.hpp"

class KernelOS : public IMonitorModule {
    public:
        KernelOS();
        ~KernelOS();

        void refreshInfo();

        void setActive(bool active) { _active = active; }
        void setPosition(unsigned int position) { _position = position; }

        bool getActive() const { return _active; }
        unsigned int getPosition() const { return _position; }

        std::string getKernelVersion() const { return (_kernelver); }
        std::string getOSName() const { return (_osname); }
    protected:
    private:
        std::string _kernelver;
        std::string _osname;

        bool _active;
        unsigned int _position;
};
