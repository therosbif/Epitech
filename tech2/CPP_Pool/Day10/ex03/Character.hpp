/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
    public:
        Character(const std::string &name);
        Character(Character &character);
        ~Character();

        Character &operator=(Character &character);

        std::string const & getName() const { return _name; };
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

        AMateria *getHolding(int idx) { return _holding[idx]; }

    protected:
    private:
        std::string _name;
        AMateria *_holding[4];
};

#endif /* !CHARACTER_HPP_ */
