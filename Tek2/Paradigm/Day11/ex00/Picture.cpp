/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD11-tanguy.bellicha
** File description:
** Picture
*/

#include "Picture.hpp"
#include <fstream>
#include <sstream>

Picture::Picture()
{
    this->data = "";
}

Picture::Picture(const std::string& file)
{
    getPictureFromFile(file);
}

Picture::~Picture()
{
}

Picture& Picture::operator=(const Picture& picture)
{
    this->data = picture.data;
    return (*this);
}

bool Picture::getPictureFromFile(const std::string& file)
{
    std::string content;
    std::ifstream myfile (file);
    std::stringstream buff;

    if (myfile.is_open()) {
        buff << myfile.rdbuf();
        this->data = buff.str();
        return (true);
    } else {
        this->data = "ERROR";
        return (false);
    }
}
