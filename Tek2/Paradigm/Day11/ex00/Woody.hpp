/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD11-tanguy.bellicha
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody : public Toy {
    public:
        Woody(std::string name, std::string ascii = "woody.txt");
        virtual ~Woody();
        virtual bool speak(std::string statement);

    protected:
    private:
};

#endif /* !WOODY_HPP_ */
