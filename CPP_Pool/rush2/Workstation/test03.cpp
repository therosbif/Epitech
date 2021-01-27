/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** test03
*/

#include "../rush2.hpp"

void MyUnitTest()
{
    Object *aBear = new Teddy("cuddles");
    Object *aPony = new LittlePony("Star");
    PapaXmasTable *Pxtable = new PapaXmasTable();
    PapaXmasConveyorBelt *PxConvoy = new PapaXmasConveyorBelt();

    Pxtable->putObject(aBear);
    Pxtable->putObject(aPony);
    aBear = Pxtable->takeObject(1);
    aPony = Pxtable->takeObject(0);
    PxConvoy->put(aBear);
    PxConvoy->put(aPony);
    aBear = PxConvoy->take();
    
}

int test_03()
{
    MyUnitTest();
    return (0);
}