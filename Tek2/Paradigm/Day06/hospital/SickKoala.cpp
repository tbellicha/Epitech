/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD06-tanguy.bellicha
** File description:
** SickKoala
*/

#include "SickKoala.hpp"
#include "iostream"

SickKoala::SickKoala(std::string name)
{
    this->name = name;
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << this->getName() << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::poke()
{
    std::cout << "Mr." << this->getName() << ": Gooeeeeerrk!!" << std::endl;
}

void SickKoala::overDrive(std::string str)
{
    size_t start_pos = 0;

    while((start_pos = str.find("Kreog!", start_pos)) != std::string::npos) {
        str.replace(start_pos, 6, "1337!");
        start_pos += 5;
    }
    std::cout << "Mr." << this->getName() << ": " << str << std::endl;
}

std::string SickKoala::getName()
{
    return (this->name);
}

bool SickKoala::takeDrug(std::string drug)
{
    if (drug == "Mars") {
        std::cout << "Mr." << this->getName() << ": Mars, and it kreogs!" << std::endl;
        return (true);
    }
    if (drug == "Kinder") {
        std::cout << "Mr." << this->getName() << ": There is a toy inside!" << std::endl;
        return (true);
    }
    std::cout << "Mr." << this->getName() << ": Goerkreog!" << std::endl;
    return (false);
}