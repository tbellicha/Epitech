/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD06-tanguy.bellicha
** File description:
** ex00
*/

#include <bits/stdc++.h>
#include <iostream>

int main (int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return (0);
    }
    for (int i = 1; i < argc; i++) {
        std::ifstream myfile (argv[i]);
        if (myfile.is_open())
            std::cout << myfile.rdbuf();
        else
            std::cerr << "my_cat: " << argv[i] << ": No such file or directory" << std::endl;
    }
    return (0);
}