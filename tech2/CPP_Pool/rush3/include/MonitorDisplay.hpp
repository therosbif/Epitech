/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-jack.goodall [WSL: Ubuntu-20.04]
** File description:
** MonitorDisplay
*/

#pragma once

#include "IMonitorDisplay.hpp"
#include "Hostname.hpp"
#include "KernelOS.hpp"
#include "Date.hpp"
#include "Cpu.hpp"
#include "Ram.hpp"
#include "Network.hpp"

class MonitorDisplay : public IMonitorDisplay {
    public:
        MonitorDisplay();
        ~MonitorDisplay();

        void changeDisplay(Hostname *hostname, bool active, unsigned int position);
        void changeDisplay(KernelOS *kernelos, bool active, unsigned int position);
        void changeDisplay(Date *date, bool active, unsigned int position);
        void changeDisplay(Cpu *cpu, bool active, unsigned int position);
        void changeDisplay(Ram *ram, bool active, unsigned int position);
        void changeDisplay(Network *network, bool active, unsigned int position);
    protected:
    private:
};
