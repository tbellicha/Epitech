/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD08-tanguy.bellicha
** File description:
** Droid
*/

#include "Droid.hpp"
#include "DroidMemory.hpp"
#include "iostream"

Droid::Droid(std::string id) : _id(id), _energy(50), _attack(25), _toughness(15)
{
    DroidMemory *tempo = new DroidMemory();
    this->_status = new std::string("Standing by");
    this->_battle_data = tempo;
    std::cout << "Droid '" << this->_id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &droid) : _id(droid._id), _energy(50), _attack(25), _toughness(15), _battle_data(droid._battle_data)
{
    if (droid._status)
        this->_status = new std::string(*(droid._status));
    else
        this->_status = new std::string("Standing by");
    std::cout << "Droid '" << this->_id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    if (this->_status)
        delete(this->_status);
    std::cout << "Droid '" << this->_id << "' Destroyed" << std::endl;
}

std::string Droid::getId() const
{
    return (this->_id);
}

size_t Droid::getEnergy() const
{
    return (this->_energy);
}

size_t Droid::getAttack() const
{
    return (this->_attack);
}

size_t Droid::getToughness() const
{
    return (this->_toughness);
}

std::string* Droid::getStatus() const
{
    return (this->_status);
}

DroidMemory* Droid::getBattleData() const
{
    return (this->_battle_data);
}

void Droid::setId(std::string id)
{
    this->_id = id;
}

void Droid::setEnergy(size_t energy)
{
    if (energy > 100)
        energy = 100;
    this->_energy = energy;
}

void Droid::setStatus(std::string* status)
{
    this->_status = status;
}

void Droid::setBattleData(DroidMemory *memo)
{
    delete (this->_battle_data);
    this->_battle_data = memo;
}

bool Droid::operator==(const Droid& droid) const
{
    if (this->_id != droid._id)
        return (false);
    if ((this->_energy != droid._energy) || (this->_attack != droid._attack))
        return (false);
    if ((this->_toughness != droid._toughness) || (*this->_status != *(droid._status)))
        return (false);
    return (true);
}

bool Droid::operator!=(const Droid& droid) const
{
    return (!(*this == droid));
}

Droid& Droid::operator<<(size_t& energy)
{
    int min;

    if (this->_energy < 100) {
        if (100 - this->_energy < energy)
            min = 100 - this->_energy;
        else
            min = energy;
        this->_energy += min;
        energy -= min;
    }
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const Droid& droid)
{
    if (droid.getEnergy() > 100)
        return (os << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", 100");
    else
        return (os << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", " << droid.getEnergy());
}

Droid& Droid::operator=(const Droid& droid)
{
    this->_id = droid._id;
    this->_energy = droid._energy;
    delete (this->_status);
    this->_status = new std::string(*(droid._status));
    return (*this);
}

bool Droid::operator()(const std::string* todo, size_t exp)
{
    std::string *tempo;
    if (this->_energy > 10) {
        this->_energy -= 10;
        tempo = new std::string(*todo);
        if (*(this->_battle_data) >= exp) {
            *tempo += " - Completed!";
            setStatus(tempo);
            this->_battle_data->setExp(this->_battle_data->getExp() + (exp / 2));
            return (true);
        } else {
            *tempo += " - Failed!";
            this->setStatus(tempo);
            this->_battle_data->setExp(this->_battle_data->getExp() + exp);
            return (false);
        }
    } else {
        this->_energy = 0;
        this->setStatus(new std::string("Battery Low"));
        return (false);
    }
}