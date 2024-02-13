/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD07pm-tanguy.bellicha
** File description:
** Parts
*/

#include "Parts.hpp"
#include "iostream"

Arms::Arms(std::string serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
}

bool Arms::isFunctional()
{
    return (this->_functional);
}

std::string Arms::serial()
{
    return (this->_serial);
}

void Arms::information()
{
    if (this->isFunctional())
        std::cout << "\t[Parts] Arms " << this->_serial << " status : OK"<< std::endl;
    else
        std::cout << "\t[Parts] Arms " << this->_serial << " status : KO"<< std::endl;
}

Legs::Legs(std::string serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
}

bool Legs::isFunctional()
{
    return (this->_functional);
}

std::string Legs::serial()
{
    return (this->_serial);
}

void Legs::information()
{
    if (this->isFunctional())
        std::cout << "\t[Parts] Legs " << this->_serial << " status : OK"<< std::endl;
    else
        std::cout << "\t[Parts] Legs " << this->_serial << " status : KO"<< std::endl;
}

Head::Head(std::string serial, bool functional)
{
    this->_serial = serial;
    this->_functional = functional;
}

bool Head::isFunctional()
{
    return (this->_functional);
}

std::string Head::serial()
{
    return (this->_serial);
}

void Head::information()
{
    if (this->isFunctional())
        std::cout << "\t[Parts] Head " << this->_serial << " status : OK"<< std::endl;
    else
        std::cout << "\t[Parts] Head " << this->_serial << " status : KO"<< std::endl;
}