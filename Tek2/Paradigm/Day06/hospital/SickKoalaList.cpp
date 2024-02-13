/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD06-tanguy.bellicha
** File description:
** SickKoalaList
*/

#include "SickKoalaList.hpp"
#include "iostream"

SickKoalaList::SickKoalaList(SickKoala *patient)
{
    this->current_patient = patient;
    this->next = nullptr;
}

SickKoalaList::~SickKoalaList()
{
}

bool SickKoalaList::isEnd()
{
    if (this->next == nullptr)
        return (true);
    return (false);
}

void SickKoalaList::append(SickKoalaList *list)
{
    if (this->isEnd() == false)
        this->next->append(list);
    else
        this->next = list;
}

SickKoala* SickKoalaList::getFromName(std::string patient_name)
{
    SickKoalaList *tempo = this;

    while (tempo != nullptr) {
        if (tempo->current_patient->getName() == patient_name)
            return (tempo->current_patient);
        tempo = tempo->next;
    }
    if (tempo->current_patient->getName() == patient_name)
        return (tempo->current_patient);
    return (nullptr);
}

SickKoalaList* SickKoalaList::getNext()
{
    return (this->next);
}

SickKoala* SickKoalaList::getContent()
{
    return (this->current_patient);
}

void SickKoalaList::dump()
{
    SickKoalaList *tempo = this;

    std::cout << "Patients: ";
    while (tempo) {
        if (tempo->current_patient)
            std::cout << tempo->current_patient->getName();
        else
            std::cout << "[nullptr]";
        if (tempo->next)
            std::cout << ", ";
        else
            std::cout << "." << std::endl;
        tempo = tempo->next;
    }
}

SickKoalaList* SickKoalaList::remove(SickKoalaList *list)
{
    if (!list)
        return (this);
    if (list == this)
        return (this->next);
    if (this->next) {
        if (this->next != list)
            this->next->remove(list);
        else
            this->next = this->next->getNext();
    }
    return (this);
}

SickKoalaList* SickKoalaList::removeFromName(std::string patient_name)
{
    if (this->current_patient->getName() == patient_name)
        return (this->getNext());
    if (this->next) {
        if (this->next->current_patient->getName() == patient_name)
            this->next = this->next->getNext();
        else
            this->next->removeFromName(patient_name);
    }
    return (this);
}