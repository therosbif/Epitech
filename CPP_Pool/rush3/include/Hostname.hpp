/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-jack.goodall
** File description:
** Hostname
*/

#ifndef HOSTNAME_HPP_
#define HOSTNAME_HPP_

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include <sys/socket.h>
#include <string>

class Hostname : public IMonitorModule {
    public:
        Hostname();
        ~Hostname();

        void setActive(bool active) { _active = active; }
        void setPosition(unsigned int position) { _position = position; }

        bool getActive() const { return _active; }
        unsigned int getPosition() const { return _position; }

        void refreshInfo();

        const std::string &getHost() const { return _hostname; };
        const std::string &getUser() const { return _user; };

    protected:
    private:
        std::string _hostname;
        std::string _user;

        bool _active;
        unsigned int _position;
};

#endif /* !HOSTNAME_HPP_ */
