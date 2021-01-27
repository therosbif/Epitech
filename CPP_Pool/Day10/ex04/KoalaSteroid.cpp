/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD10-jack.goodall
** File description:
** KoalaSteroid
*/

#include "KoalaSteroid.hpp"

KoalaSteroid::KoalaSteroid() : _name("KoalaSteroid")
{
}

KoalaSteroid::~KoalaSteroid()
{
}

std::string KoalaSteroid::beMined(DeepCoreMiner *miner) const
{
    return "Zazium";
}

std::string KoalaSteroid::beMined(StripMiner *miner) const
{
    return "Koalite";
}
