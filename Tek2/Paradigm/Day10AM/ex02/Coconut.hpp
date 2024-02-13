/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD10am-tanguy.bellicha
** File description:
** Coconut
*/

#ifndef COCONUT_HPP_
#define COCONUT_HPP_

#include "FruitBox.hpp"
#include "Fruit.hpp"

class Coconut : public Fruit {
    public:
        Coconut();
        virtual ~Coconut();
        FruitBox* const* organizeCoconut(Coconut const* const* coconuts);

    protected:
    private:
};

#endif /* !COCONUT_HPP_ */
