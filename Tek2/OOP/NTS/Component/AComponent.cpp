/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** AComponent
*/

#include "AComponent.hpp"
#include <iostream>

nts::AComponent::AComponent()
{
}

nts::AComponent::~AComponent()
{
}

void nts::AComponent::simulate(std::size_t tick)
{
    (void)tick;
}

void nts::AComponent::setLink(std::size_t pin, nts ::IComponent &other, std::size_t otherPin)
{
    (void)pin;
    (void)other;
    (void)otherPin;
}

void nts::AComponent::dump() const
{
    std::cout << "dump\n";
}