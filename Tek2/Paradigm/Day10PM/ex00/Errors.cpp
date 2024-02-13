/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD10pm-tanguy.bellicha
** File description:
** Errors
*/

#include "Errors.hpp"

const char* NasaError::what() const noexcept
{
    return (this->_message.c_str());
}

NasaError::NasaError(std::string const &message, std::string const &component) : _message(message), _component(component)
{
    
}


MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component) : NasaError(message, component)
{
    
}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component) : NasaError(message, component)
{
    
}

UserError::UserError(std::string const &message, std::string const &component) : NasaError(message, component)
{
    
}

CommunicationError::CommunicationError(std::string const &message) : NasaError(message, "CommunicationDevice")
{
    
}

std::string const& NasaError::getComponent() const
{
    return (this->_component);
}