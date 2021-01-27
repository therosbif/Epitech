/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-jack.goodall [WSL: Ubuntu-20.04]
** File description:
** Network
*/

#include "Network.hpp"

Network::Network()
{
}

Network::~Network()
{
}

std::string getRxLoad(std::string interface)
{
    std::fstream file_rx;
    std::string rx_bytes;

    file_rx.open("/sys/class/net/" + interface + "/statistics/rx_bytes", file_rx.in);
    if (file_rx.is_open()) {
        std::getline(file_rx, rx_bytes);
        file_rx.close();
        return (rx_bytes);
    }
    std::cout << "Error: Cannot find requested interface" << std::endl;
    return ("ERROR");
}

std::string getTxLoad(std::string interface)
{
    std::fstream file_tx;
    std::string tx_bytes;

    file_tx.open("/sys/class/net/" + interface + "/statistics/tx_bytes", file_tx.in);
    if (file_tx.is_open()) {
        std::getline(file_tx, tx_bytes);
        file_tx.close();
        return (tx_bytes);
    }
    std::cout << "Error: Cannot find requested interface" << std::endl;
    return ("ERROR");
}

void Network::clearVectors()
{
    _interface.clear();
    _address.clear();
    _rx.clear();
    _tx.clear();
}

void Network::refreshInfo()
{
    struct ifaddrs *ifaddr;
    struct ifaddrs *tmp;

    clearVectors();

    if (getifaddrs(&ifaddr) == -1) {
        std::cout << "Error: Cannot read ifaddrs" << std::endl;
        return;
    }

    for (tmp = ifaddr; tmp != NULL; tmp = tmp->ifa_next) {
        if (tmp->ifa_addr->sa_family != AF_INET) {
            continue;
        }
        _interface.push_back(tmp->ifa_name);
        _address.push_back(inet_ntoa(((struct sockaddr_in *)tmp->ifa_addr)->sin_addr));
        _rx.push_back(getRxLoad(tmp->ifa_name));
        _tx.push_back(getTxLoad(tmp->ifa_name));
        _icount += 1;
    }

    if (ifaddr!=NULL) freeifaddrs(ifaddr);
}
