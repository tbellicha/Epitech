/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** IMonitorDisplay
*/

#include "IMonitorDisplay.hpp"

IMonitorDisplay::IMonitorDisplay()
{
    this->_displayCPU = true;
    this->_displayInfo = true;
    this->_displayNetwork = true;
    this->_displayRAM = true;
    this->_displayStockage = true;
}

IMonitorDisplay::~IMonitorDisplay()
{
}

bool IMonitorDisplay::getDisplayCPU() const
{
    return this->_displayCPU;
}

bool IMonitorDisplay::getDisplayInfo() const
{
    return this->_displayInfo;
}

bool IMonitorDisplay::getDisplayRAM() const
{
    return this->_displayRAM;
}

bool IMonitorDisplay::getDisplayNetwork() const
{
    return this->_displayNetwork;
}

bool IMonitorDisplay::getDisplayStockage() const
{
    return this->_displayStockage;
}

void IMonitorDisplay::setDisplayCPU(bool status)
{
    this->_displayCPU = status;
}

void IMonitorDisplay::setDisplayInfo(bool status)
{
    this->_displayInfo = status;
}

void IMonitorDisplay::setDisplayRAM(bool status)
{
    this->_displayRAM = status;
}

void IMonitorDisplay::setDisplayNetwork(bool status)
{
    this->_displayNetwork = status;
}

void IMonitorDisplay::setDisplayStockage(bool status)
{
    this->_displayStockage = status;
}
