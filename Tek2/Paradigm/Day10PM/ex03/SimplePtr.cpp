/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD10pm-tanguy.bellicha
** File description:
** SimplePtr
*/

#include "SimplePtr.hpp"

SimplePtr::SimplePtr(BaseComponent* rawPtr) : _rawPtr(rawPtr)
{
}

SimplePtr::SimplePtr(SimplePtr const&)
{
}

SimplePtr::~SimplePtr()
{
    delete this->_rawPtr;
}

BaseComponent* SimplePtr::get() const
{
    return (this->_rawPtr);
}

SimplePtr& SimplePtr::operator=(SimplePtr const&)
{
    return (*this);
}