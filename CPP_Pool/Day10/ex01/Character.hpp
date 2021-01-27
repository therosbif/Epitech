/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "AWeapon.hpp"
#include "AEnemy.hpp"

#define MIN(x, y) ((x < y) ? x : y)

class Character{
    public:
        Character(const std::string &name);
        virtual ~Character();

        void recoverAP() { _ap += MIN(10, 40 - _ap); };

        void equip(AWeapon *weapon) { _weapon = weapon; };
        void attack(AEnemy *enemy);

        const std::string getName() const { return _name; };
        int getAP() const { return _ap; };
        bool isArmed() const { return (_weapon != nullptr); };
        AWeapon *getWeapon() const { return _weapon; };

    protected:
    private:
        const std::string _name;
        int _ap;
        AWeapon *_weapon;
};

std::ostream &operator<<(std::ostream &out, Character &character);

#endif /* !CHARACTER_HPP_ */
