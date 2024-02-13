/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGRUSH3-johan.chrillesen
** File description:
** main
*/

#include "include.hpp"
#include "CheckParams.hpp"

int main(int argc, char** argv)
{
    if (!check_params(argc, argv))
        return (RETURN_ERROR);
    return 0;
}
