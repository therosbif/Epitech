/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-jack.goodall
** File description:
** GraphWindow.hpp
*/


#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "KernelOS.hpp"
#include "Date.hpp"
#include "Hostname.hpp"
#include "Ram.hpp"
#include "Cpu.hpp"

class GraphWindow {
    public:
        GraphWindow();
        ~GraphWindow();
        std::string getYear(Date *);
        std::string getMonth(Date *);
        std::string getDay(Date *);
        std::string getHour(Date *);
        std::string getMin(Date *);
        std::string getSec(Date *);


        std::string getHost(Hostname *);
        std::string getUser(Hostname *);


        std::string getOSName(KernelOS *);
        std::string getKernelVersion(KernelOS *);

        unsigned int getCores(Cpu *);
        int getTemp(Cpu *);
        float getTotal(Cpu *);

        unsigned long long int getTotalMem(Ram *);
        unsigned long long int getAvailMem(Ram *);
        unsigned long long int getFreeMem(Ram *);
        unsigned long long int getUsedMem(Ram *);
    protected:
};

void loopSfml();
std::string getHost();
std::string getUser();

std::string getOSName();
std::string getKernelVersion();

std::string getYear();
std::string getMonth();
std::string getDay();
std::string getHour();
std::string getMin();
std::string getSec();
unsigned int getCores();
int getTemp();
float getTotal();
unsigned long long int getTotalMem();
unsigned long long int getAvailMem();
unsigned long long int getFreeMem();
unsigned long long int getUsedMem();