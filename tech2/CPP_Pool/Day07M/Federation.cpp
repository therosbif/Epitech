/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD07M-jack.goodall
** File description:
** Federation
*/

#include "Federation.hpp"
#include <string>

Federation::Starfleet::Ship::Ship(const int length, const int width,
    const std::string name, const short maxWarp, int torpedo) : _length(length),
    _width(width), _name(name), _maxWarp(maxWarp), _core(nullptr), _home(EARTH),
    _location(_home), _shield(100), _photonTorpedo(torpedo)
{
    std::cout << "The ship USS " << _name << " has been finished." << std::endl
        << "It is " << _length << " m in length and "
        << _width << " m in width." << std::endl
        << "It can go to Warp " << _maxWarp << "!" << std::endl;
        if (torpedo)
            std::cout << "Weapons are set: " << torpedo << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore(void)
{
    std::string stablility = std::string((_core->checkReactor()->isStable()) ? "stable" : "unstable");

    std::cout << "USS " << _name << ": The core is " << stablility << " at the time." << std::endl;
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
    _captain = captain;
    std::cout << captain->getName() <<
        ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (warp <= _maxWarp && _core->checkReactor()->isStable()) {
        _location = _home;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(void)
{
    if (_core->checkReactor()->isStable()) {
        _location = _home;
        return true;
    }
    return false;
}

int Federation::Starfleet::Ship::getShield(void)
{
    return _shield;
}

int Federation::Starfleet::Ship::getTorpedo(void)
{
    return _photonTorpedo;
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    if (_photonTorpedo > 0) {
        _photonTorpedo--;
        std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
        target->setShield(target->getShield() -  50);
        if (!_photonTorpedo)
            std::cout << _name << ": No more torpedo to fire, " << _captain->getName() << "!" << std::endl;
    } else
        std::cout << _name << ": No enough torpedoes to fire, " << _captain->getName() << "!" << std::endl;
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if ((_photonTorpedo - torpedoes) >= 0) {
        _photonTorpedo -= torpedoes;
        std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
        target->setShield(target->getShield() -  50);
        if (!_photonTorpedo)
            std::cout << _name << ": No more torpedo to fire, " << _captain->getName() << "!" << std::endl;
    } else
        std::cout << _name << ": No enough torpedoes to fire, " << _captain->getName() << "!" << std::endl;
}




Federation::Ship::Ship(const int length, const int width,
    const std::string name) : _length(length),
    _width(width), _name(name), _maxWarp(1), _core(nullptr), _home(VULCAN), _location(_home)
{
    std::cout << "The independent ship " << _name << " just finished its construction." << std::endl
        << "It is " << _length << " m in length and "
        << _width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << _name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore(void)
{
    std::string stablility = std::string((_core->checkReactor()->isStable()) ? "stable" : "unstable");

    std::cout << _name << ": The core is " << stablility << " at the time." << std::endl;
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move(int warp)
{
    if (warp <= _maxWarp && _core->checkReactor()->isStable()) {
        _location = _home;
        return true;
    }
    return false;
}

bool Federation::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable()) {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move(void)
{
    if (_core->checkReactor()->isStable()) {
        _location = _home;
        return true;
    }
    return false;
}

WarpSystem::Core *Federation::Ship::getCore(void)
{
    return _core;
}



Federation::Starfleet::Captain::Captain(std::string name) : _name(name), _age(0)
{
}

Federation::Starfleet::Captain::~Captain(void)
{
}

std::string Federation::Starfleet::Captain::getName(void)
{
    return _name;
}

int Federation::Starfleet::Captain::getAge(void)
{
    return _age;
}

void Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}




Federation::Starfleet::Ensign::Ensign(std::string name) : _name(name)
{
    std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign(void)
{
}
