/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD07pm-tanguy.bellicha
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"
#include "iostream"

KoalaBot::KoalaBot(std::string name)
{
    this->_name = name;
}

void KoalaBot::setParts(Arms &arms)
{
    this->_arms = arms;
}

void KoalaBot::setParts(Legs &legs)
{
    this->_legs = legs;
}

void KoalaBot::setParts(Head &head)
{
    this->_head = head;
}

void KoalaBot::swapParts(Arms &arms)
{
    this->setParts(arms);
}

void KoalaBot::swapParts(Legs &legs)
{
    this->setParts(legs);
}

void KoalaBot::swapParts(Head &head)
{
    this->setParts(head);
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << this->_name << std::endl;
    this->_arms.information();
    this->_legs.information();
    this->_head.information();
}

bool KoalaBot::status() const
{
    if (this->_arms.isFunctional() && this->_legs.isFunctional() && this->_head.isFunctional()) {
        return (true);
    }
    return (false);
}
