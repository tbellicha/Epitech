/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD07am-tanguy.bellicha
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor()
{
    this->_stability = true;
}

bool WarpSystem::QuantumReactor::isStable()
{
    return (this->_stability);
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    this->_stability = stability;
}

WarpSystem::Core::Core(QuantumReactor *QR)
{
    this->_coreReactor = QR;
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return (this->_coreReactor);
}