/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-jack.goodall
** File description:
** IElf
*/

#include "IElf.hpp"

IElf::IElf(ITable *table, IConveyorBelt *belt) : _table(table), _belt(belt), _holding(nullptr)
{
}

IElf::~IElf()
{
}

void IElf::take(Object *object)
{
    if (_holding == nullptr) {
        object->isTaken();
        _holding = object;
    } else
        std::cerr << "Already holding an Object." << std::endl;
}

void IElf::wrapThis(Object *object)
{
    if (_holding != nullptr && _holding->getType() == "Wrap")
        ((Wrap *)(_holding))->wrapMeThat(object);
    else
        std::cerr << "Not Holding a Wrap." << std::endl;
}

void IElf::put(IConveyorBelt *belt)
{
    if (_holding != nullptr)
        if (belt->put(_holding))
            _holding = nullptr;
    else
        std::cerr << "Not holding an Object." << std::endl;
}

void IElf::put(ITable *table)
{
    if (_holding != nullptr)
        if (table->putObject(_holding))
            _holding = nullptr;
    else
        std::cerr << "Not holding an Object." << std::endl;
}

PapaXmasElf::PapaXmasElf(ITable *table, IConveyorBelt *belt) : IElf(table, belt)
{
}

static int get_first(std::string *table, const std::string &to_find)
{
    for (int i = 0; table[i] != "[null]"; i++) {
        if (table[i] == to_find) return i;
    }
    return 11;
}

void PapaXmasElf::wrapGift()
{
    std::string *table = _table->inspectTable();
    int first_box;
    int first_gp;
    int first_toy;

    while (first_toy != 11) {
        first_box = get_first(table, "Box");
        first_gp = get_first(table, "GiftPaper");
        first_toy = get_first(table, "Toy");
        if (first_box == 11 || first_gp == 11) {
            _belt->in((first_box == 11) ? "Box" : "GiftPaper");
            take(_belt->take());
            put(_table);
            table = _table->inspectTable();
            continue;
        }
        _holding = _table->takeObject(first_box);
        wrapThis(_table->takeObject(first_toy));
        put(_table);
        _holding = _table->takeObject(first_gp);
        wrapThis(_table->takeObject(_table->getSize() - 1));
        put(_belt);
        _belt->out();
    }
}
