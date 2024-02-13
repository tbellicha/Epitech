/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD06-tanguy.bellicha
** File description:
** KoalaNurse
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

#include "string"
#include "SickKoala.hpp"

class KoalaNurse {
    public:
        KoalaNurse(int ID);
        ~KoalaNurse();
        void giveDrug(std::string drug, SickKoala *patient);
        std::string readReport(std::string filename);
        bool working;
        void timeCheck();
        int getID();

    protected:
    private:
        int ID;
};

#endif /* !KOALANURSE_HPP_ */
