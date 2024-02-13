/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD06-tanguy.bellicha
** File description:
** main
*/

#include <iostream>
#include <string>
#include <iomanip>

int main() {
    double value;
    std::string type;

    std::cin >> value >> type;
    std::cout.precision(3);
    if (type == "Fahrenheit") {
        value = 5.0 / 9.0 * (value - 32);
        std::cout << std::setw(16) << std::fixed << value  << std::setw(16) << "Celsius"<< std::endl;
    }
    if (type == "Celsius") {
        value = value * (9.0/5.0) + 32;
        std::cout << std::setw(16) << std::fixed << value << std::setw(16) << "Fahrenheit" << std::endl;
    }
}