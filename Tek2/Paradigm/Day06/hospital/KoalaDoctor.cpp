/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD06-tanguy.bellicha
** File description:
** KoalaDoctor
*/

#include "KoalaDoctor.hpp"
#include <iostream>
#include <fstream>

KoalaDoctor::KoalaDoctor(std::string name)
{
    this->name = name;
    this->working = false;
    std::cout << "Dr." << this->name << ": I'm Dr." << this->name << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
}

void KoalaDoctor::diagnose(SickKoala *patient)
{
    std::string list[5] = {"Mars", "Kinder", "Crunch", "Maroilles", "Eucalyptus leaf"};
    std::cout << "Dr." << this->getName() << ": So what's goerking you Mr." << patient->getName() << "?" << std::endl;
    std::ofstream myFile(patient->getName() + ".txt");
    myFile << list[random()%5];
    patient->poke();
}

std::string KoalaDoctor::getName()
{
    return (this->name);
}

void KoalaDoctor::timeCheck()
{
    if (this->working == false) {
        std::cout << "Dr." << this->getName() << ": ";
        std::cout << "Time to get to work!" << std::endl;
        this->working = true;
    } else {
        std::cout << "Dr." << this->getName() << ": ";
        std::cout << "Time to go home to my eucalyptus forest!" << std::endl;
        this->working = false;
    }
}