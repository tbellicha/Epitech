/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD09-tanguy.bellicha
** File description:
** Priest
*/

#include "Priest.hpp"
#include "iostream"

Priest::Priest(const std::string& name, int power) : Peasant(name, power), Enchanter(name, power)
{
    std::cout << this->_name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << this->_name << " finds peace." << std::endl;
}

void Priest::rest()
{
    if (!(this->checkIsAble(0)))
        return ;
    this->_power = 100;
    this->_health = 100;
    std::cout << this->_name << " prays." << std::endl;
}