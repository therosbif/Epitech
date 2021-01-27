/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-jack.goodall
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <cpuid.h>
#include <map>

struct cpu_time {
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
    unsigned long long steal;
    unsigned long long total;
};

class Cpu : public IMonitorModule {
    public:
        Cpu();
        ~Cpu() = default;

        void refreshInfo();

        void setActive(bool active) { _active = active; }
        void setPosition(unsigned int position) { _position = position; }

        bool getActive() const { return _active; }
        unsigned int getPosition() const { return _position; }

        unsigned int getCores() const { return _cores; };
        float getTotal() const { return _total; };
        std::vector<float> getLoad() const { return _load; };
        int getTemp() const { return _temperature; };
        const std::string &getModel() const { return _model; };

    protected:
        bool readvalue();
        float get_load(size_t core) const;
    private:
        unsigned int _cores;
        std::vector<struct cpu_time *> _time;
        std::vector<struct cpu_time *> _time_prev;
        float _total;
        std::vector<float> _load;
        int _temperature;

        std::string _model;

        bool _active;
        unsigned int _position;
};

#endif /* !CORE_HPP_ */
