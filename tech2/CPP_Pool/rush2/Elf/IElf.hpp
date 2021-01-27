/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-jack.goodall
** File description:
** IElf
*/

#ifndef IELF_HPP_
#define IELF_HPP_

#include "../Wrap/Wrap.hpp"
#include "../Toys/Toy.hpp"
#include "../Wrap/Box.hpp"
#include "../Wrap/GiftPaper.hpp"
#include "../Workstation/ConveyorBelt.hpp"
#include "../Workstation/Table.hpp"

class IElf {
    public:
        IElf(ITable *table, IConveyorBelt *belt);
        ~IElf();

        virtual void take(Object *wrap);

        virtual void put(IConveyorBelt *belt);
        virtual void put(ITable *belt);

        virtual void wrapThis(Object *object);

    protected:
        IConveyorBelt *_belt;
        ITable *_table;
        Object *_holding;
    private:
};

class PapaXmasElf : public IElf {
    public:
        PapaXmasElf(ITable *table, IConveyorBelt *belt);

        void wrapGift();
    private:
};

#endif /* !IELF_HPP_ */
