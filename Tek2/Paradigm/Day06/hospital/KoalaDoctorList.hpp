/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD06-tanguy.bellicha
** File description:
** KoalaDoctorList
*/

#ifndef KOALADOCTORLIST_HPP_
#define KOALADOCTORLIST_HPP_

#include "KoalaDoctor.hpp"

class KoalaDoctorList {
    public:
        KoalaDoctorList(KoalaDoctor *doctor);
        ~KoalaDoctorList();
        bool isEnd();
        void append(KoalaDoctorList *node);
        KoalaDoctor *getFromName(std::string doctor_name);
        KoalaDoctorList *remove(KoalaDoctorList *);
        KoalaDoctorList *removeFromName(std::string doctor_name);
        void dump();
        KoalaDoctor *current_doctor;
        KoalaDoctorList *next;

    protected:
    private:
};

#endif /* !KOALADOCTORLIST_HPP_ */
