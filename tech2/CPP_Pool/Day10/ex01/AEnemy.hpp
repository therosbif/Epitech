/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** AEnemy
*/

#ifndef AENEMY_HPP_
#define AENEMY_HPP_

#include <iostream>
#include <string>

class AEnemy {
    public:
        AEnemy(int hp, const std::string &type);
        virtual ~AEnemy();

        virtual void takeDamage(int damage);

        const std::string getType() const { return _type; };
        int getHP() const { return _health; };

    protected:
    private:
        int _health;
        const std::string _type;
};

#endif /* !AENEMY_HPP_ */
