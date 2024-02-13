/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** main
*/

#include "NanoTekSpice.hpp"
#include "Exception.hpp"
#include "Parser.hpp"
#include "SpecialComponent.hpp"
#include <iostream>
#include <string>

const char *help = "retry with ./nanotekspice file";

int main(int argc, char **argv)
{
    nts::NanoTekSpice nano;

    if (argc != 2) {
        std::cout << help << std::endl;
        return 84;
    }
    try {
        nts::Parser parser(argv[1]);
        parser.ComputeParsing();
    } catch (nts::Exception const& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    nano.run();
    return 0;
}