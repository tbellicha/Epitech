/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD06-tanguy.bellicha
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include "string"
#include "SickKoala.hpp"

class KoalaDoctor {
    public:
        KoalaDoctor(std::string name);
        ~KoalaDoctor();
        void diagnose(SickKoala *patient);
        bool working;
        void timeCheck();
        std::string getName();

    protected:
    private:
        std::string name;
};

#endif /* !KOALADOCTOR_HPP_ */
