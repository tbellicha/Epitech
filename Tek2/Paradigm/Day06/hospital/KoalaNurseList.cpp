/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD06-tanguy.bellicha
** File description:
** KoalaNurseList
*/

#include "KoalaNurseList.hpp"
#include "iostream"

KoalaNurseList::KoalaNurseList(KoalaNurse *current_nurse)
{
    this->current_nurse = current_nurse;
    this->next = nullptr;
}

KoalaNurseList::~KoalaNurseList()
{
}

bool KoalaNurseList::isEnd()
{
    if (this->next == nullptr)
        return (true);
    return (false);
}

void KoalaNurseList::append(KoalaNurseList *list)
{
    if (this->isEnd() == false)
        this->next->append(list);
    else
        this->next = list;
}

KoalaNurse* KoalaNurseList::getFromID(int ID)
{
    KoalaNurseList *tempo = this;

    while (tempo != nullptr) {
        if (tempo->current_nurse->getID() == ID)
            return (tempo->current_nurse);
        tempo = tempo->next;
    }
    if (tempo->current_nurse->getID() == ID)
        return (tempo->current_nurse);
    return (nullptr);
}

void KoalaNurseList::dump()
{
    KoalaNurseList *tempo = this;

    std::cout << "Nurses: ";
    while (tempo) {
        if (tempo->current_nurse)
            std::cout << tempo->current_nurse->getID();
        else
            std::cout << "[nullptr]";
        if (tempo->next)
            std::cout << ", ";
        else
            std::cout << "." << std::endl;
        tempo = tempo->next;
    }
}

KoalaNurseList* KoalaNurseList::remove(KoalaNurseList *list)
{
    if (!list)
        return (this);
    if (list == this)
        return (this->next);
    if (this->next) {
        if (this->next != list)
            this->next->remove(list);
        else
            this->next = this->next->next;
    }
    return (this);
}

KoalaNurseList* KoalaNurseList::removeFromID(int ID)
{
    KoalaNurseList *tempo = this;
    KoalaNurseList *node_before = nullptr;

    while (tempo != nullptr) {
        if (tempo->current_nurse && tempo->current_nurse->getID() == ID) {
            if (node_before) {
                node_before->next = tempo->next;
                tempo->next = nullptr;
                break;
            }
            else {
                node_before = tempo->next;
                tempo->next = nullptr;
            }
        }
        node_before = tempo;
        tempo = tempo->next;
    }
    return (this);
}