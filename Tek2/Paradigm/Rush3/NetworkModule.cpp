/*
** EPITECH PROJECT, 2022
** RUSH3
** File description:
** NetworkModule
*/

#include "NetworkModule.hpp"
#include "AllMonitors.hpp"
#include <string>
#include <iostream>
#include <fstream>

NetworkModule::NetworkModule()
{
}

NetworkModule::~NetworkModule()
{
}

void NetworkModule::setUp(double up)
{
    this->_up = up;
}

void NetworkModule::setDown(double down)
{
    this->_down = down;
}

double NetworkModule::getUp() const
{
    return this->_up;
}

double NetworkModule::getDown() const
{
    return this->_down;
}