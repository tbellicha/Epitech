/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD09-tanguy.bellicha
** File description:
** Enchanter
*/

#include "Enchanter.hpp"
#include "iostream"

Enchanter::Enchanter(const std::string& name, int power) : Peasant(name, power)
{
    std::cout << this->_name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << this->_name << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    int nb_power = 0;
    int damage = 0;

    if (!(this->checkIsAble(nb_power)))
        return (0);
    this->_power -= nb_power;
    std::cout << this->_name << " doesn't know how to fight." << std::endl;
    return (damage);
}

int Enchanter::special()
{
    int nb_power = 50;
    int damage = 99;

    if (!(this->checkIsAble(nb_power)))
        return (0);
    this->_power -= nb_power;
    std::cout << this->_name << " casts a fireball." << std::endl;
    return (damage);
}

void Enchanter::rest()
{
    if (!(this->checkIsAble(0)))
        return ;
    this->_power = 100;
    std::cout << this->_name << " meditates." << std::endl;
}