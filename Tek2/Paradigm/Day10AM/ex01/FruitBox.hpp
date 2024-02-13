/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD10am-tanguy.bellicha
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox {
    public:
        FruitBox(int size);
        virtual ~FruitBox();

        int nbFruits() const;
        bool putFruit(Fruit* f);
        Fruit* pickFruit();
        FruitNode* head() const;

    protected:
        int _size;
        int _nb;
        FruitNode* _header;
    private:
};

#endif /* !FRUITBOX_HPP_ */
