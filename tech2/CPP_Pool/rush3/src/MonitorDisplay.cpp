/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-jack.goodall [WSL: Ubuntu-20.04]
** File description:
** MonitorDisplay
*/

#include "MonitorDisplay.hpp"

MonitorDisplay::MonitorDisplay()
{
}

MonitorDisplay::~MonitorDisplay()
{
}

void MonitorDisplay::changeDisplay(Hostname *hostname, bool active, unsigned int position)
{
    hostname->setActive(active);
    hostname->setPosition(position);
}

void MonitorDisplay::changeDisplay(Date *date, bool active, unsigned int position)
{
    date->setActive(active);
    date->setPosition(position);
}

void MonitorDisplay::changeDisplay(KernelOS *kernelos, bool active, unsigned int position)
{
    kernelos->setActive(active);
    kernelos->setPosition(position);
}

void MonitorDisplay::changeDisplay(Cpu *cpu, bool active, unsigned int position)
{
    cpu->setActive(active);
    cpu->setPosition(position);
}

void MonitorDisplay::changeDisplay(Ram *ram, bool active, unsigned int position)
{
    ram->setActive(active);
    ram->setPosition(position);
}

void MonitorDisplay::changeDisplay(Network *network, bool active, unsigned int position)
{
    network->setActive(active);
    network->setPosition(position);
}
