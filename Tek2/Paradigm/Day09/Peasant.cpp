/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD09-tanguy.bellicha
** File description:
** Peasant
*/

#include "Peasant.hpp"
#include "iostream"

Peasant::Peasant(const std::string& name, int power) : _name(name)
{
    if (power > 100)
        power = 100;
    this->_power = power;
    this->_health = 100;
    std::cout << this->_name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << this->_name << " is back to his crops." << std::endl;
}

const std::string& Peasant::getName() const
{
    return (this->_name);
}

int Peasant::getPower() const
{
    return (this->_power);
}

int Peasant::getHp() const
{
    return (this->_health);
}

bool Peasant::checkIsAble(int nb_power) const
{
    if (this->_health <= 0) {
        std::cout << this->_name << " is out of combat." << std::endl;
        return (false);
    }
    if (this->_power < 0 + nb_power) {
        std::cout << this->_name << " is out of power." << std::endl;
        return (false);
    }
    return (true);
}

int Peasant::attack()
{
    int nb_power = 10;
    int damage = 5;

    if (!(this->checkIsAble(nb_power)))
        return (0);
    this->_power -= nb_power;
    std::cout << this->_name << " tosses a stone." << std::endl;
    return (damage);
}

int Peasant::special()
{
    int nb_power = 0;
    int damage = 0;

    if (!(this->checkIsAble(nb_power)))
        return (0);
    this->_power -= nb_power;
    std::cout << this->_name << " doesn't know any special move." << std::endl;
    return (damage);
}

void Peasant::rest()
{
    if (!(this->checkIsAble(0)))
        return ;
    this->_power += 30;
    if (this->_power > 100)
        this->_power = 100;
    std::cout << this->_name << " takes a nap." << std::endl;
}

void Peasant::damage(int damage)
{
    if (!(this->checkIsAble(0)))
        return ;
    else {
        if (this->_health - damage > 0)
            std::cout << this->_name << " takes " << damage << " damage." << std::endl;
        else
            std::cout << this->_name << " is out of combat." << std::endl;
        this->_health -= damage;
        if (this->_health < 0)
            this->_health = 0;
    }
}