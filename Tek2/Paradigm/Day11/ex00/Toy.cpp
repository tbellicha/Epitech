/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD11-tanguy.bellicha
** File description:
** Toy
*/

#include "Toy.hpp"
#include <iostream>

Toy::Toy()
{
    this->_type = BASIC_TOY;
    this->_name = "toy";
    this->_picture.data = "";
}

Toy::Toy(ToyType type, std::string name, std::string filename)
{
    this->_type = type;
    this->_name = name;
    if (!setAscii(filename))
        this->_picture.data = "ERROR";
}

Toy::Toy(Toy const& toy)
{
    this->_type = toy._type;
    this->_name = toy._name;
    this->_picture = toy._picture;
}

Toy::~Toy()
{
}

std::string Toy::Error::what() const
{
    switch (this->type) {
        case PICTURE:
            return ("bad new illustration");

        case SPEAK:
            return ("wrong mode");

        default:
            return ("");

    }
}

std::string Toy::Error::where() const
{
    switch (this->type) {
        case PICTURE:
            return ("setAscii");

        case SPEAK:
            return ("speak_es");

        default:
            return ("");

    }
}

std::ostream& operator<<(std::ostream& os, const Toy& toy)
{
    return (os << toy.getName() << std::endl << toy.getAscii() << std::endl);
}

Toy::ToyType Toy::getType() const
{
    return (this->_type);
}

const std::string& Toy::getName() const
{
    return (this->_name);
}

void Toy::setName(const std::string& name)
{
    this->_name = name;
}

const std::string& Toy::getAscii() const
{
    return (this->_picture.data);
}

bool Toy::setAscii(const std::string& filename)
{
    if (this->_picture.getPictureFromFile(filename))
        return (true);
    this->_error.type = Error::PICTURE;
    return (false);
}

Toy& Toy::operator=(const Toy& toy)
{
    this->_name = toy._name;
    this->_type = toy._type;
    this->_picture = toy._picture;
    return (*this);
}

bool Toy::speak(std::string statement)
{
    std::cout << this->getName() << " \"" << statement << "\"" << std::endl;
    return (true);
}

bool Toy::speak_es(std::string statement)
{
    this->_error.type = Error::SPEAK;
    (void)statement;
    return (false);
}

Toy& Toy::operator<<(std::string picture)
{
    this->_picture.data = picture;
    return (*this);
}

Toy::Error::Error()
{
    this->type = UNKNOWN;
}

Toy::Error const& Toy::getLastError() const
{
    return (this->_error);
}
