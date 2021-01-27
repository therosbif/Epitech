/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-jack.goodall
** File description:
** IMonitorDisplay
*/

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

#include "IMonitorModule.hpp"

class IMonitorDisplay {
    public:
        virtual ~IMonitorDisplay() {};

        virtual void changeDisplay(IMonitorModule *module, bool active, unsigned int position) = 0;
    protected:
    private:
};

#endif /* !IMONITORDISPLAY_HPP_ */
