/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD11-tanguy.bellicha
** File description:
** Buzz
*/

#include "Buzz.hpp"
#include <iostream>

Buzz::Buzz(std::string name, std::string filename) : Toy(BUZZ, name, filename)
{
}

Buzz::~Buzz()
{
}

bool Buzz::speak(std::string statement)
{
    std::cout << "BUZZ: " << this->getName() << " \"" << statement << "\"" << std::endl;
    return (true);
}

bool Buzz::speak_es(std::string statement)
{
    std::cout << "BUZZ: " << this->getName() << " senorita \"" << statement << "\" senorita" << std::endl;
    return (true);
}
