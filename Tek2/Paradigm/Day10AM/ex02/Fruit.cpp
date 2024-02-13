/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD10am-tanguy.bellicha
** File description:
** Fruit
*/

#include "Fruit.hpp"

Fruit::Fruit(std::string name, int vitamins) : name(name), _vitamins(vitamins)
{
}

Fruit::Fruit() : _vitamins(0)
{
}

Fruit::~Fruit()
{
}

std::string Fruit::getName() const
{
    return (this->name);
}

int Fruit::getVitamins() const
{
    return (this->_vitamins);
}
