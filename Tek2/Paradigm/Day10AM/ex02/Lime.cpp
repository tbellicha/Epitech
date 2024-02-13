/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD10am-tanguy.bellicha
** File description:
** Lime
*/

#include "Lime.hpp"

Lime::Lime() {
    this->name = "lime";
    this->_vitamins = 2;
}

Lime::Lime(Lime const &f) : Lemon() {
    this->name = f.getName();
    this->_vitamins = f.getVitamins();
}

Lime::~Lime()
{
}
