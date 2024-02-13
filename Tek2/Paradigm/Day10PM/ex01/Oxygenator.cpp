#include <iostream>
#include "Errors.hpp"
#include "Oxygenator.hpp"

Oxygenator::Oxygenator() :
    _quantity(0)
{
}

void    Oxygenator::generateOxygen()
{
    this->_quantity += 10;
}

void    Oxygenator::useOxygen(int quantity)
{
    if (this->_quantity <= 10)
        throw LifeCriticalError("Not enough oxygen to live.", "Oxygenator");
    if (this->_quantity <= 20)
        throw MissionCriticalError("Not enough oxygen to continue the mission.", "Oxygenator");
    this->_quantity -= quantity;
}
