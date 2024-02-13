/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD09-tanguy.bellicha
** File description:
** Knight
*/

#include "Knight.hpp"
#include "iostream"

Knight::Knight(const std::string& name, int power) : Peasant(name, power)
{
    std::cout << this->_name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << this->_name << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    int nb_power = 10;
    int damage = 20;

    if (!(this->checkIsAble(nb_power)))
        return (0);
    this->_power -= nb_power;
    std::cout << this->_name << " strikes with his sword." << std::endl;
    return (damage);
}

int Knight::special()
{
    int nb_power = 30;
    int damage = 50;

    if (!(this->checkIsAble(nb_power)))
        return (0);
    this->_power -= nb_power;
    std::cout << this->_name << " impales his enemy." << std::endl;
    return (damage);
}

void Knight::rest()
{
    if (!(this->checkIsAble(0)))
        return ;
    this->_power += 50;
    if (this->_power > 100)
        this->_power = 100;
    std::cout << this->_name << " eats." << std::endl;
}