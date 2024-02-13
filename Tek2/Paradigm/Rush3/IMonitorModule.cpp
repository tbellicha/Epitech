/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGRUSH3-johan.chrillesen
** File description:
** IMonitorModule
*/

#include "IMonitorModule.hpp"

IMonitorModule::IMonitorModule()
{
}

IMonitorModule::~IMonitorModule()
{
}

std::string IMonitorModule::getTitle() const
{
    return (this->title);
}

void IMonitorModule::setTitle(std::string title)
{
    this->title = title;
}
