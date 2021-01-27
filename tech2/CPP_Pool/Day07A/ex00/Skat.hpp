/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD07A-jack.goodall
** File description:
** Skat
*/

#ifndef SKAT_HPP_
#define SKAT_HPP_

#include <iostream>

class Skat {
    public:
        Skat(const std::string &name = "Bob", int stimPaks = 15);
        ~Skat();

        int &stimPaks();
        void stimPaks(int &);
        const std::string &name();

        void shareStimPaks(int number, int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status() const;
	private:
        const std::string &_name;
        int &_stimPaks;
};

#endif /* !SKAT_HPP_ */
