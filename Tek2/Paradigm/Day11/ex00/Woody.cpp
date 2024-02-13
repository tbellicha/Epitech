/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD11-tanguy.bellicha
** File description:
** Woody
*/

#include "Woody.hpp"
#include <iostream>

Woody::Woody(std::string name, std::string filename) : Toy(WOODY, name, filename)
{
}

Woody::~Woody()
{
}

bool Woody::speak(std::string statement)
{
    std::cout << "WOODY: " << this->getName() << " \"" << statement << "\"" << std::endl;
    return (true);
}
