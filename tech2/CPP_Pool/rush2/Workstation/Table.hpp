/*
** EPITECH PROJECT, 2021
** Workstation
** File description:
** Table
*/

#ifndef TABLE_HPP_
#define TABLE_HPP_

#include <iostream>
#include <vector>
#include "../Toys/Object.hpp"

class ITable {
    public:
        virtual Object *takeObject(int) = 0;
        virtual bool putObject(Object *) = 0;
        virtual std::string *lookTable() = 0;
        virtual std::string *inspectTable() = 0;
        virtual int getSize() = 0;
};

class PapaXmasTable : public ITable {
    public:
        PapaXmasTable();
        ~PapaXmasTable();
        std::string *lookTable();
        std::string *inspectTable();
        Object *takeObject(int);
        bool putObject(Object *);
        int getSize() { return _ontable.size(); };

    protected:
    private:
    std::vector<Object*> _ontable;
    void collapses();
};

class TableRand : public PapaXmasTable {
    public:
        TableRand();
        ~TableRand();
};

#endif /* !TABLE_HPP_ */
