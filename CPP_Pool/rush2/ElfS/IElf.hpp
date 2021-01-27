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
        IElf(IConveyorBelt *belt, ITable *table);
        ~IElf();

        virtual void take_belt();
        virtual void take_table(int i);
        virtual void put_belt();
        virtual void put_table();

        Wrap *wrapIt(Wrap *wrap);

    protected:
        IConveyorBelt *_belt;
        ITable *_table;
        Object *_holding;
    private:
};

class PapaXmasElf : public IElf {
    public:
        PapaXmasElf(IConveyorBelt *belt, ITable *table);
        ~PapaXmasElf();
        int first(std::string);
        bool make_gift(int);
        int Find_gift(std::string);
        int work();
    private:
};

#endif /* !IELF_HPP_ */