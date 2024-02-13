/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD06-tanguy.bellicha
** File description:
** KoalaNurse
*/

#include "KoalaNurse.hpp"
#include "iostream"
#include <bits/stdc++.h>

KoalaNurse::KoalaNurse(int ID)
{
    this->ID = ID;
    this->working = false;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse [" << this->getID() << "]: Finally some rest !" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
    patient->takeDrug(drug);
}

int KoalaNurse::getID()
{
    return (this->ID);
}

std::string KoalaNurse::readReport(std::string filename)
{
    std::string result;
    if (filename.find(".report") == 0)
        return ("");
    std::ifstream myfile (filename);
    if (myfile.is_open()) {
        getline(myfile, result);
        std::cout << "Nurse [" << this->getID() << "]: Kreog! Mr.";
        std::cout << filename.substr(0, filename.find(".report")) << " needs a " << result << std::endl;
        return (result);
    }
    return ("");
}

void KoalaNurse::timeCheck()
{
    if (this->working == false) {
        std::cout << "Nurse [" << this->getID() << "]: ";
        std::cout << "Time to get to work!" << std::endl;
        this->working = true;
    } else {
        std::cout << "Nurse [" << this->getID() << "]: ";
        std::cout << "Time to go home to my eucalyptus forest!" << std::endl;
        this->working = false;
    }
}