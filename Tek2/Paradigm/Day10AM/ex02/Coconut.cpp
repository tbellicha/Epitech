/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD10am-tanguy.bellicha
** File description:
** Coconut
*/

#include "Coconut.hpp"

Coconut::Coconut() :  Fruit("coconut", 15)
{
}

Coconut::~Coconut()
{
}

FruitBox* const* Coconut::organizeCoconut(Coconut const* const* coconuts)
{
    int i_coc = 0;
    int nb_coc = 0;
    int i_box;

    while (coconuts[nb_coc])
        nb_coc++;
    FruitBox** result = new FruitBox*[(nb_coc / 6) + 2];
    result[(nb_coc / 6) + 1] = nullptr;
    while (i_coc < nb_coc) {
        i_box = i_coc % 6;
        if (!i_box)
            result[i_box] = new FruitBox(6);
        i_box = i_coc / 6;
        for (int i = 0; i < i_box; i++)
            result[i_box]->putFruit(new Coconut());
        i_coc++;
    }
    return (result);
}