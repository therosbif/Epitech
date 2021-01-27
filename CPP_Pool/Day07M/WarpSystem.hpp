/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD07M-jack.goodall
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

#include <iostream>
#include <string>

namespace WarpSystem
{
    class QuantumReactor {
        public:
            QuantumReactor();
            ~QuantumReactor();

            bool isStable();
            void setStability(bool);
        private:
            bool _stability;
    };
    class Core {
        public:
            Core(QuantumReactor *);
            ~Core();

            QuantumReactor *checkReactor();
        private:
            QuantumReactor *_coreReactor;
    };
}

#endif /* !WARPSYSTEM_HPP_ */
