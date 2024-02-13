/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD06-tanguy.bellicha
** File description:
** SickKoalaList
*/

#ifndef SICKKOALALIST_HPP_
#define SICKKOALALIST_HPP_

#include "SickKoala.hpp"

class SickKoalaList {
    public:
        SickKoalaList(SickKoala *patients);
        ~SickKoalaList();
        bool isEnd();
        void append(SickKoalaList *node);
        SickKoala *getFromName(std::string patient_name);
        SickKoalaList *remove(SickKoalaList *list);
        SickKoalaList *removeFromName(std::string patient_name);
        SickKoala *getContent();
        SickKoalaList *getNext();
        void dump();
        SickKoala *current_patient;
        SickKoalaList *next;

    protected:
    private:
};

#endif /* !SICKKOALALIST_HPP_ */