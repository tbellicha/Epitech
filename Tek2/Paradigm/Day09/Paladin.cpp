/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD09-tanguy.bellicha
** File description:
** Paladin
*/

#include "Paladin.hpp"
#include "iostream"

Paladin::Paladin(const std::string& name, int power) : Peasant(name, power), Knight(name, power), Enchanter(name, power), Priest(name, power)
{
    std::cout << this->Knight::_name << " fights for the light." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << this->Knight::_name << " is blessed." << std::endl;
}

int Paladin::attack()
{
    return (this->Knight::attack());
}

int Paladin::special()
{
    return (this->Enchanter::special());
}

void Paladin::rest()
{
    return (this->Priest::rest());
}

void Paladin::damage(int damage)
{
    this->Priest::damage(damage);
}