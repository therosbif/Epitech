/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** AWeapon
*/

#ifndef AWEAPON_HPP_
#define AWEAPON_HPP_

#include <iostream>
#include <string>

class AWeapon {
    public:
        AWeapon(const std::string &name, int apcost, int damage);
        virtual ~AWeapon();

        const std::string getName() const { return _name; };
        int getAPCost() const { return _apCost; };
        int getDamage() const { return _damage; };

        virtual void attack() const = 0;

    protected:
    private:
        const std::string _name;
        int _apCost;
        int _damage;
};

#endif /* !AWEAPON_HPP_ */
