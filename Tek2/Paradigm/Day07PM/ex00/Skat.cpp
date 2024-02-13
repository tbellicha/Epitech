/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD07pm-tanguy.bellicha
** File description:
** Skat
*/

#include "Skat.hpp"
#include "iostream"

Skat::Skat(const std::string &name, int stimPaks)
{
    this->_name = name;
    this->_stimPaks = stimPaks;
}

Skat::~Skat()
{
}

int &Skat::stimPaks()
{
    return (this->_stimPaks);
}

const std::string &Skat::name()
{
    return (this->_name);
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (this->_stimPaks < number) {
        std::cout << "Don't be greedy" << std::endl;
        return ;
    }
    std::cout << "Keep the change." << std::endl;
    this->_stimPaks -= number;
    stock += number;
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0) {
        std::cout << "Hey boya, did you forget something?" << std::endl;
        return ;
    }
    this->_stimPaks += number;
}

void Skat::useStimPaks()
{
    if (this->_stimPaks > 0) {
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
        this->_stimPaks--;
    }
    else
        std::cout << "Mediiiiiic" << std::endl;
}

void Skat::status()
{
    std::cout << "Soldier " << this->_name << " reporting " << this->stimPaks() << " stimpaks remaining sir!" << std::endl;
}