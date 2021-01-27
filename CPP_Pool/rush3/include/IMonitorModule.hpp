/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-jack.goodall
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

#include <unistd.h>
#include <stdlib.h>

class IMonitorModule {
    public:
        virtual ~IMonitorModule() {};

        virtual void refreshInfo() = 0;

        virtual void setActive(bool active) = 0;
        virtual void setPosition(unsigned int position) = 0;

        virtual bool getActive() const = 0;
        virtual unsigned int getPosition() const = 0;

    protected:
    private:
};

#endif /* !IMONITORMODULE_HPP_ */
