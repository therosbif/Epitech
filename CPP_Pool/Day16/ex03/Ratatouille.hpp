/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD16-jack.goodall
** File description:
** Ratatouille
*/

#ifndef RATATOUILLE_HPP_
#define RATATOUILLE_HPP_

#include <sstream>
#include <iostream>

class Ratatouille {
    public:
        Ratatouille() = default;
        Ratatouille(const Ratatouille &r) { _pot << r.kooc(); };
        ~Ratatouille() = default;
        Ratatouille &operator=(const Ratatouille &);

        Ratatouille &addVegetable(unsigned char);
        Ratatouille &addCondiment(unsigned int);
        Ratatouille &addSpice(double);
        Ratatouille &addSauce(const std::string &);

        std::string kooc() const { return _pot.str(); };

    protected:
    private:
        std::ostringstream _pot;
};

#endif /* !RATATOUILLE_HPP_ */
