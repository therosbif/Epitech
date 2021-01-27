/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-jack.goodall
** File description:
** Cpu
*/

#include "Cpu.hpp"

Cpu::Cpu()
{
    refreshInfo();

    _active = 0;
    _position = 0;
}

static std::vector<std::string> split(std::string str, std::string token)
{
    std::vector<std::string> result;
    while (str.size())
    {
        size_t index = str.find(token);
        if (index != std::string::npos)
        {
            result.push_back(str.substr(0, index));
            str = str.substr(index + token.size());
            if (str.size() == 0)
                result.push_back(str);
        }
        else
        {
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

bool Cpu::readvalue()
{
    _time_prev.swap(_time);
    _time.clear();

    std::ifstream in;
    std::string str;

    in.open("/proc/stat", std::ios::in);
    while (std::getline(in, str) && str.compare(0, 3, "cpu") == 0)
    {
        if (str.compare(0, 4, "cpu ") == 0)
            continue;

        auto values = split(str, " ");

        _time.emplace_back(new struct cpu_time);
        _time.back()->user = std::stoull(values[1], nullptr, 10);
        _time.back()->nice = std::stoull(values[2], nullptr, 10);
        _time.back()->system = std::stoull(values[3], nullptr, 10);
        _time.back()->idle = std::stoull(values[4], nullptr, 10);
        _time.back()->steal = std::stoull(values[8], nullptr, 10);
        _time.back()->total = _time.back()->user + _time.back()->nice + _time.back()->system +
                             _time.back()->idle + _time.back()->steal;
    }
    in.close();
    return !_time.empty();
}

void Cpu::refreshInfo()
{
    if (!readvalue())
        return;
    _cores = _time.size();

    for (size_t i = 0; i < _cores; i++) {
        float load = get_load(i);
        _total += load;
        _load.emplace_back(load);
    }

    std::ifstream in("/sys/class/thermal/thermal_zone0/temp");
    std::string line;

    std::getline(in, line);
    _temperature = std::strtol(line.c_str(), nullptr, 10);
    _temperature /= 1000;

    std::ifstream info_in("/proc/cpuinfo");

    while (std::getline(info_in, line)) {
        if (line.compare(0, 10, "model name")) continue;
        _model = line.substr(line.find(':') + 2);
        break;
    }
    info_in.close();
    in.close();
}

float Cpu::get_load(size_t core) const
{
    if (_time.empty() || _time_prev.empty())
        return 0;
    else if (core >= _time.size() || core >= _time_prev.size())
        return 0;

    auto &last = _time[core];
    auto &prev = _time_prev[core];

    auto last_idle = last->idle;
    auto prev_idle = prev->idle;

    auto diff = last->total - prev->total;

    if (diff == 0)
        return 0;

    float percentage = 100.0f * (diff - (last_idle - prev_idle)) / diff;

    return percentage;
}
