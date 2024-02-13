/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD06-tanguy.bellicha
** File description:
** KoalaNurseList
*/

#ifndef KOALANURSELIST_HPP_
#define KOALANURSELIST_HPP_

#include "KoalaNurse.hpp"

class KoalaNurseList {
    public:
        KoalaNurseList(KoalaNurse *nurse);
        ~KoalaNurseList();
        bool isEnd();
        void append(KoalaNurseList *node);
        KoalaNurse *getFromID(int ID);
        KoalaNurseList *remove(KoalaNurseList *list);
        KoalaNurseList *removeFromID(int ID);
        void dump();
        KoalaNurse *current_nurse;
        KoalaNurseList *next;

    protected:
    private:
};

#endif /* !KOALANURSELIST_HPP_ */