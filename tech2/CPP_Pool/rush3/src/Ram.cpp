/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-jack.goodall
** File description:
** Ram
*/

#include "Ram.hpp"

Ram::Ram()
{
    refreshInfo();
}

void Ram::refreshInfo()
{
    std::fstream in;
    std::string line;
    std::map<std::string, unsigned long long int> parse;

    in.open("/proc/meminfo", std::ios::in);
    while (std::getline(in, line)) {
        size_t sep = line.find(':');
        size_t value_start = line.find_first_of("123456789", sep);

        if (sep == std::string::npos || value_start == std::string::npos)
            continue;

        std::string id = line.substr(0, sep);
        unsigned long long int value = std::strtoull(&line[value_start], nullptr, 10);
        parse[id] = value;
    }
    _memtotal = parse["MemTotal"];
    _memavail = parse["MemAvailable"];
    _memfree = parse["MemFree"];
    _memused = _memavail - _memfree;

    _swaptotal = parse["SwapTotal"];
    _swapfree = parse["SwapFree"];
    _swapused = _swaptotal - _swapfree;

    _mem_perc = static_cast<double>((static_cast<long double>(_memused) * 100) / static_cast<long double>(_memavail));
    _swap_perc = static_cast<double>((static_cast<long double>(_swapused) * 100) / static_cast<long double>(_swaptotal));
}
