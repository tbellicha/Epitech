/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD07am-tanguy.bellicha
** File description:
** Federation
*/

#include "Borg.hpp"
#include "Federation.hpp"
#include "iostream"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;
    this->_location = _home;
    this->_shield = 100;
    this->_photonTorpedo = torpedo;

    std::cout << "The ship USS " << this->_name << " has been finished." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
    if (this->_photonTorpedo != 0) {
        std::cout << "Weapons are set: " << this->_photonTorpedo << " torpedoes ready." << std::endl;
    }
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    if (this->_core->checkReactor()->isStable())
        std::cout << "USS " << this->_name << ": The core is stable at the time." << std::endl;
    else
        std::cout << "USS " << this->_name << ": The core is unstable at the time." << std::endl;
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *new_captain)
{
    this->captain = new_captain;

    std::cout << this->captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable() == true) {
        this->_location = d;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(int warp)
{
    return (move(warp, this->_home));
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    return (move(this->_maxWarp, d));
}

bool Federation::Starfleet::Ship::move()
{
    return (move(this->_maxWarp, this->_home));
}

int Federation::Starfleet::Ship::getShield()
{
    return (this->_shield);
}

int Federation::Starfleet::Ship::getTorpedo()
{
    return (this->_photonTorpedo);
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    this->_shield = shield;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    this->_photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    this->fire(1, target);
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (this->_photonTorpedo < torpedoes) {
        std::cout << this->_name << ": No enough torpedoes to fire, " << this->captain->getName() << "!" << std::endl;
        return ;
    }
    this->setTorpedo(this->getTorpedo() - torpedoes);
    target->setShield(target->getShield() - (50 * torpedoes));
    std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
    if (this->getTorpedo() == 0)
        std::cout << this->_name << ": No more torpedo to fire, " << this->captain->getName() << "!" << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = 1;

    std::cout << "The independent ship " << this->_name << " just finished its construction." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
    std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    if (this->_core->checkReactor()->isStable())
        std::cout << this->_name << ": The core is stable at the time." << std::endl;
    else
        std::cout << this->_name << ": The core is unstable at the time." << std::endl;
}

WarpSystem::Core *Federation::Ship::getCore()
{
    return (this->_core);
}

Federation::Starfleet::Captain::Captain(std::string name)
{
    this->_name = name;
}

int Federation::Starfleet::Captain::getAge()
{
    return (this->_age);
}

std::string Federation::Starfleet::Captain::getName()
{
    return (this->_name);
}

void Federation::Starfleet::Captain::setAge(int age)
{
    this->_age = age;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    this->_name = name;

    std::cout << "Ensign " << this->_name << ", awaiting orders." << std::endl;
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable() == true) {
        this->_location = d;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move(int warp)
{
    return (move(warp, this->_home));
}

bool Federation::Ship::move(Destination d)
{
    return (move(this->_maxWarp, d));
}

bool Federation::Ship::move()
{
    return (move(this->_maxWarp, this->_home));
}