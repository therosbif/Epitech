/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD08-jack.goodall
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <iostream>

#define MIN(x, y) ((x > y) ? y : x)

class Droid {
    public:
        Droid(std::string serial = "");
        Droid(const Droid &droid);
        ~Droid();

        std::string getId() const { return Id; };
        size_t getEnergy() const { return Energy; };
        size_t getAttack() const { return Attack; };
        size_t getToughness() const { return Toughness; };
        std::string *getStatus() const { return Status; };

        void setId(std::string id) { Id = id; };
        void setEnergy(size_t energy) { Energy = energy; };
        void setStatus(std::string *status) { delete Status; Status = status; };

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
};

std::ostream &operator<< (std::ostream &, const Droid &);

#endif /* !DROID_HPP_ */
