/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD08-tanguy.bellicha
** File description:
** Carrier
*/

#include "Carrier.hpp"
#include "iostream"

Carrier::Carrier(std::string id) : _id(id), _energy(300), _attack(100), _toughness(90)
{
    this->_id = id;
    this->_speed = 0;
    this->_droids = new Droid*[5];
    for (int i = 0; i < 5; i++)
        this->_droids[i] = nullptr;
}

Carrier::~Carrier()
{
    for (int i = 0; i < 5; i++)
        if (this->_droids[i])
            delete (this->_droids[i]);
}

size_t Carrier::getSpeed()
{
    return (this->_speed);
}

Carrier& Carrier::operator<<(Droid* droid)
{
    for (int i = 0; i < 5; i++) {
        if (!(this->_droids[i])) {
            this->_droids[i] = droid;
            this->_speed = 100 - (10 * (i + 1));
            return (*this);
        }
    }
    return (*this);
}

Carrier& Carrier::operator>>(Droid* droid)
{
    (void)droid;
    for (int i = 0; i < 5; i++) {
        if (this->_droids[i]) {
            droid = this->_droids[i];
            this->_droids[i] = nullptr;
            return (*this);
        }
    }
    return (*this);
}

void Carrier::printCarrier() const
{
    for (int i = 0; i < 5; i++) {
        if (this->_droids[i]) {
            std::cout << "[" << i << "] " << this->_droids[i]->getId() << std::endl; 
        }
    }
}