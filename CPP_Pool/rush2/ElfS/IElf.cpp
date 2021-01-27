/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-jack.goodall
** File description:
** IElf
*/

#include "IElf.hpp"

PapaXmasElf::PapaXmasElf(IConveyorBelt *belt, ITable *table)
: IElf(belt, table)
{}
PapaXmasElf::~PapaXmasElf()
{}

IElf::IElf(IConveyorBelt *belt, ITable *table)
: _belt(belt), _table(table), _holding(nullptr)
{}

IElf::~IElf()
{
}

void IElf::take_belt()
{
    if (_holding != nullptr) {
        std::cerr << "Already holding an Object." << std::endl;
        return ;
    }
    _holding = _belt->take();
}

void IElf::take_table(int i)
{
    if (_holding != nullptr) {
        std::cerr << "Already holding an Object." << std::endl;
        return ;
    }
    _holding = _table->takeObject(i);
}

void IElf::put_belt()
{
    if (_holding == nullptr) {
        std::cerr << "Not holding an Object." << std::endl;
        return ;
    }
    _belt->put(_holding);
    _holding = nullptr;
}

void IElf::put_table()
{
    if (_holding == nullptr) {
        std::cerr << "Not holding an Object." << std::endl;
        return ;
    }
    _table->putObject(_holding);
    _holding = nullptr;
}

Wrap *IElf::wrapIt(Wrap *wrap)
{
    if (_holding != nullptr)
        wrap->wrapMeThat(_holding);
    else
        std::cerr << "Not Holding anything" << std::endl;
    return wrap;
}

int PapaXmasElf::first(std::string to)
{
    std::string *type = _table->inspectTable();

    for (int i = 0 ; type[i] != "[null]" ; i++) {
        if (type[i] == to)
            return i;
    }
    return 11;
}

int PapaXmasElf::work()
{
    int ted  = this->Find_gift("Teddy");
    int ponny = this->Find_gift("LittlePony");

    std::cout << "o'pa ere's somin'wron'in da box!" << std::endl;
    std::cout << "bu' i pac'ed " << ted << " fluffington an' " <<
    ponny << " friendship horsy" << std::endl;
    return ted + ponny;
}

int PapaXmasElf::Find_gift(std::string type)
{
    int count = 0;
    int toy = 0;

    while (toy != 11) {
        toy = first(type);
        count += make_gift(toy);
    }
    return count;
}

bool PapaXmasElf::make_gift(int toy)
{

    int gp = first("GiftPaper");
    int box = first("Box");

    if (toy == 11)
        return false;
    while (box == 11 || gp == 11) {
        _belt->in((box == 11) ? "Box" : "GiftPaper");
        take_belt();
        put_table();
        gp = first("GiftPaper");
        box = first("Box");
    }
    _holding = _table->takeObject(toy);
    _holding = wrapIt(((Box *)_table->takeObject(first("Box")))->openMe());
    _holding = wrapIt(((GiftPaper *)_table->takeObject(first("GiftPaper")))->openMe());
    put_belt();
    _belt->out();
    return true;
}