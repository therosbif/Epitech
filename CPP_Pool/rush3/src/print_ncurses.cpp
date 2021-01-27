/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3
-jack.goodall
** File description:
** main
*/


#include "print_ncurses.hpp"
#include "Hostname.hpp"
#include "Cpu.hpp"
#include "KernelOS.hpp"
#include <ctime>
#include "Ram.hpp"
#include "Network.hpp"

print_ncurses::print_ncurses()
{
}

print_ncurses::~print_ncurses()
{
}

void print_name(void)
{
    Hostname host;
    std::string name = host.getHost();
    std::string user = host.getUser();
    move(0, 0);
    printw("hostname: %s\nuser: %s", name.data(), user.data());
}

void print_date(void)
{
    time_t now = time(0);
   
    char* dt = ctime(&now);
    move(2, 0);
    printw("date : %s", dt);
    now = time(0);
}

void print_kernel0S(void)
{
    KernelOS kernel;
    std::string kernelver = kernel.getKernelVersion();
    std::string osname = kernel.getOSName();

    move(3, 0);
    printw("kernel version : %s\nos name: %s", kernelver.data(), osname.data());
}

void print_temp_cpu(void)
{
    Cpu cpu;
    move(5, 0);
    printw("core = %d", cpu.getCores());
    move(6, 0);
    printw("cpu :%f", cpu.getTotal());
    move(7, 0);
    printw("cpu température: %d", cpu.getTemp());
}

void print_ram()
{
    Ram ram;
    move(8, 0);
    printw("ram = %llu/%llu Kb", ram.getUsedMem(), ram.getTotalMem());
    move(9, 0);
    printw("swap = %llu/%llu Kb", ram.getUsedSwap(), ram.getTotalSwap());
}

void main_ncurses(void)
{
    initscr();
	while(1) {
        clear();
        print_name();
        print_date();
        print_kernel0S();
        print_temp_cpu();
        print_ram();
        sleep(1);
        refresh();
    }
    endwin();
}