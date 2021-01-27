/*
** EPITECH PROJECT, 2021
** Workstation
** File description:
** Table
*/

#include "Table.hpp"
#include "../Wrap/Box.hpp"
#include "../Wrap/GiftPaper.hpp"
#include "../Toys/LittlePony.hpp"
#include "../Toys/Teddy.hpp"

PapaXmasTable::PapaXmasTable()
{
    std::cout << "New table created" << std::endl;
}

PapaXmasTable::~PapaXmasTable()
{
    this->collapses();
    std::cout << "Well... this table is useless now" << std::endl;
}

ITable *createTable()
{
    return (new (PapaXmasTable));
}

std::string *PapaXmasTable::lookTable()
{
    size_t tab = this->_ontable.size();
    std::string *tmp = new std::string[tab + 1];

    for (size_t i = 0; i < tab; i++) {
        tmp[i] = this->_ontable[i]->getTitle();
    }
    tmp[tab] = nullptr;
    return (tmp);
}

std::string *PapaXmasTable::inspectTable()
{
    size_t tab = this->_ontable.size();
    std::string *tmp = new std::string[tab + 1];

    for (size_t i = 0; i < tab; i++) {
        tmp[i] = this->_ontable[i]->getType();
    }
    tmp[tab] = "[null]";
    return (tmp);
}

Object *PapaXmasTable::takeObject(int i)
{
    size_t obj_to_take;
    Object *tmp;

    if (i < 0) {
        std::cerr << "Can't take an object in negative" << std::endl;
        return (nullptr);
    }
    obj_to_take = i;

    if (obj_to_take < this->_ontable.size()) {
        tmp = this->_ontable[obj_to_take];
        tmp->isTaken();
        this->_ontable.erase(this->_ontable.begin() + obj_to_take);
        return (tmp);
    } else {
        std::cerr << "The table can only handle 10 objects so you can't take further" << std::endl;
        return (nullptr);
    }
}

bool PapaXmasTable::putObject(Object *object)
{
    if (!object) {
        std::cerr << "Empty gift is not a good joke" << std::endl;
        return false;
    }
    if (this->_ontable.size() < 10) {
        this->_ontable.push_back(object);
        std::cout << "A new " << object->getTitle() << " is put on the table";
        std::cout << ", it's a " << object->getType() << std::endl;
        return true;
    } else {
        //Destroy table + objects on table
        collapses();
    }
    return false;
}

void PapaXmasTable::collapses()
{
    while (!_ontable.empty())
        _ontable.erase(_ontable.end());
    std::cout << "* CRRRSSHHH *" << std::endl;
    std::cout << "The table collapses due to too much gifts" << std::endl;
    //delete this;
}

TableRand::TableRand()
{
    for (int i = 0 ; i < 10 ; i++) {
        switch (i % 4) {
            case (0):
                this->putObject(new Box);
                break;
            case (1):
                this->putObject(new Teddy("ted_" + std::to_string(i)));
                break;
            case (2):
                this->putObject(new GiftPaper);
                break;
            case (3):
                this->putObject(new LittlePony("aLP_" + std::to_string(i)));
                break;
        }
    }
}

TableRand::~TableRand()
{}
