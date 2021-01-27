/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-jack.goodall [WSL: Ubuntu-20.04]
** File description:
** Network
*/

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sys/types.h>
#include <ifaddrs.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class Network {
    public:
        Network();
        ~Network();

        void refreshInfo();

        void clearVectors();

        void setActive(bool active) { _active = active; }
        void setPosition(unsigned int position) { _position = position; }

        int getInterfaceCount() const { return (_icount); }
        std::string getInterface(int index) const { return (_interface.at(index)); }
        std::string getAddress(int index) const { return (_address.at(index)); }
        std::string getRx(int index) const { return (_rx.at(index)); }
        std::string getTx(int index) const { return (_tx.at(index)); }
    protected:
    private:
        int _icount;
        std::vector<std::string> _interface;
        std::vector<std::string> _address;
        std::vector<std::string> _rx;
        std::vector<std::string> _tx;

        bool _active;
        unsigned int _position;
};
