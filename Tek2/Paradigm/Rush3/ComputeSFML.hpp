/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGRUSH3-johan.chrillesen
** File description:
** ComputeSFML
*/

#ifndef COMPUTESFML_HPP_
#define COMPUTESFML_HPP_

#include <SFML/Graphics.hpp>
#include "InfoModule.hpp"
#include "AllMonitors.hpp"
#include <unistd.h>
#include <iostream>
#include <list>
#include <string>

enum EType {
    Infos,
    Jauge
};

typedef struct infos_t {
    sf::Vector2f position;
    sf::Vector2f size;
    EType type;
    std::string title;
    double value;
    std::string str_value;

} infos_s;


#endif /* !COMPUTESFML_HPP_ */