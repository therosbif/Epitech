/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** test04
*/

#include "../rush2.hpp"

int test_04()
{
    TableRand *Pxtable = new TableRand();
    PapaXmasConveyorBelt *PxConvoy = new PapaXmasConveyorBelt();
    auto *elf = new PapaXmasElf(PxConvoy, Pxtable);

    return elf->work();
}