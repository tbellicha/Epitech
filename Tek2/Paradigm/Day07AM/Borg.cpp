/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD07am-tanguy.bellicha
** File description:
** Borg
*/

#include "Borg.hpp"
#include "iostream"

Borg::Ship::Ship(int weaponfrquency, short repair)
{
    this->_side = 300;
    this->_maxWarp = 9;
    this->_weaponFrequency = weaponfrquency;
    this->_repair = repair;
    this->_shield = 100;

    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    this->_coreReactor = core;
}

void Borg::Ship::checkCore()
{
    if (this->_coreReactor->checkReactor()->isStable())
        std::cout << "Everything is in order." << std::endl;
    else
        std::cout << "Critical failure imminent." << std::endl;
}
bool Borg::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location && this->_coreReactor->checkReactor()->isStable() == true) {
        this->_location = d;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move(int warp)
{
    return (move(warp, this->_home));
}

bool Borg::Ship::move(Destination d)
{
    return (move(this->_maxWarp, d));
}

bool Borg::Ship::move()
{
    return (move(this->_maxWarp, this->_home));
}

int Borg::Ship::getShield()
{
    return (this->_shield);
}

void Borg::Ship::setShield(int shield)
{
    this->_shield = shield;
}

int Borg::Ship::getWeaponFrequency()
{
    return (this->_weaponFrequency);
}

void Borg::Ship::setWeaponFrequency(int frequency)
{
    this->_weaponFrequency = frequency;
}

short Borg::Ship::getRepair()
{
    return (this->_repair);
}

void Borg::Ship::setRepair(short repair)
{
    this->_repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    std::cout << "Firing on target with " << this->getWeaponFrequency() << "GW frequency." << std::endl;
    target->setShield(target->getShield() - this->_weaponFrequency);
}

void Borg::Ship::fire(Federation::Ship *target)
{
    target->getCore()->checkReactor()->setStability(false);
}

void Borg::Ship::repair()
{
    if (this->_repair > 0) {
        this->setShield(100);
        this->_repair--;
        std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
    }
    else
        std::cout << "Energy cells depleted, shield weakening." << std::endl;
}