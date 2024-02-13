/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD06-tanguy.bellicha
** File description:
** KoalaDoctorList
*/

#include "KoalaDoctorList.hpp"
#include "iostream"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *doctor)
{
    this->current_doctor = doctor;
    this->next = nullptr;
}

KoalaDoctorList::~KoalaDoctorList()
{
}

bool KoalaDoctorList::isEnd()
{
    if (this->next == nullptr)
        return (true);
    return (false);
}

void KoalaDoctorList::append(KoalaDoctorList *list)
{
    if (this->isEnd() == false)
        this->next->append(list);
    else
        this->next = list;
}

KoalaDoctor* KoalaDoctorList::getFromName(std::string doctor_name)
{
    KoalaDoctorList *tempo = this;

    while (tempo != nullptr) {
        if (tempo->current_doctor->getName() == doctor_name)
            return (tempo->current_doctor);
        tempo = tempo->next;
    }
    if (tempo->current_doctor->getName() == doctor_name)
        return (tempo->current_doctor);
    return (nullptr);
}

void KoalaDoctorList::dump()
{
    KoalaDoctorList *tempo = this;

    std::cout << "doctors: ";
    while (tempo) {
        if (tempo->current_doctor)
            std::cout << tempo->current_doctor->getName();
        else
            std::cout << "[nullptr]";
        if (tempo->next)
            std::cout << ", ";
        else
            std::cout << "." << std::endl;
        tempo = tempo->next;
    }
}

KoalaDoctorList* KoalaDoctorList::remove(KoalaDoctorList *list)
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

KoalaDoctorList* KoalaDoctorList::removeFromName(std::string doctor_name)
{
    if (this->current_doctor->getName() == doctor_name)
        return (this->next);
    if (this->next) {
        if (this->next->current_doctor->getName() == doctor_name)
            this->next = this->next->next;
        else
            this->next->removeFromName(doctor_name);
    }
    return (this);
}