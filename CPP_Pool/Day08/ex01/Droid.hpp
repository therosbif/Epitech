/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD08-jack.goodall
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <iostream>
#include "DroidMemory.hpp"

#define MIN(x, y) ((x > y) ? y : x)

class Droid {
    public:
        Droid(std::string);
        Droid(const Droid &);
        ~Droid();

        std::string getId() const { return Id; };
        size_t getEnergy() const { return Energy; };
        size_t getAttack() const { return Attack; };
        size_t getToughness() const { return Toughness; };
        std::string *getStatus() const { return Status; };
        DroidMemory *getBattleData() const { return BattleData; };

        void setId(std::string id) { Id = id; };
        void setEnergy(size_t energy) { Energy = energy; };
        void setStatus(std::string *status) { delete Status; Status = status; };
        void setBattleData(DroidMemory *mem) { delete BattleData; BattleData = mem; };

        bool operator== (const Droid &) const;
        bool operator!= (const Droid &) const;
        Droid &operator<< (size_t &);
        Droid &operator= (const Droid &droid);
    protected:
    private:
        std::string Id;
        size_t Energy;
        const size_t Attack;
        const size_t Toughness;
        std::string *Status;
        DroidMemory *BattleData;
};

std::ostream &operator<< (std::ostream &, const Droid &);

#endif /* !DROID_HPP_ */
