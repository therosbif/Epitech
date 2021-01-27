/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** test04
*/

#include "../rush2.hpp"

void MyUnitTest()
{
    Object *aBear = new Teddy("OURS");
    Object *aPony = new LittlePony("PONEY");
    PapaXmasTable *Pxtable = new PapaXmasTable();
    PapaXmasConveyorBelt *PxConvoy = new PapaXmasConveyorBelt();
    auto *elf = new PapaXmasElf(Pxtable, PxConvoy);

    elf->take(aBear);
    elf->put(PxConvoy);
    elf->take(aPony);
    elf->put(Pxtable);
    elf->wrapThis(aBear);
    elf->wrapGift();
}