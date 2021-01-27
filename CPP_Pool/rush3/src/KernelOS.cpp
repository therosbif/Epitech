/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-jack.goodall [WSL: Ubuntu-20.04]
** File description:
** KernelOS
*/

#include "KernelOS.hpp"

KernelOS::KernelOS()
{
    refreshInfo();

    _active = 0;
    _position = 0;
}

KernelOS::~KernelOS()
{
}

void KernelOS::refreshInfo()
{
    struct utsname info;

    if (uname(&info)) {
        std::cout << "Error: Cannot read system information" << std::endl;
        return;
    } else {
        _osname = info.sysname;
        _kernelver = info.release;
    }
}
