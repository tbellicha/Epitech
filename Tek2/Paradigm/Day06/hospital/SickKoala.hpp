/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD06-tanguy.bellicha
** File description:
** SickKoala
*/

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_

#include "string"

class SickKoala {
    public:
        SickKoala(std::string name);
        ~SickKoala();
        void poke();
        bool takeDrug(std::string drug);
        void overDrive(std::string string);
        std::string getName();

    protected:
    private:
        std::string name;
};

#endif /* !SICKKOALA_HPP_ */
