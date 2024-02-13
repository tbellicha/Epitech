/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD10am-tanguy.bellicha
** File description:
** LittleHand
*/

#include "LittleHand.hpp"
#include "FruitBox.hpp"

void LittleHand::sortFruitBox(FruitBox& unsorted, FruitBox& lemons, FruitBox& bananas, FruitBox& limes)
{
    FruitBox tmp(unsorted.nbFruits());
    Fruit *fruit = unsorted.pickFruit();

    while (fruit) {
        switch (fruit->getVitamins()) {
            case 2:
                if (!limes.putFruit(fruit))
                    tmp.putFruit(fruit);
                break;

            case 3:
                if (!lemons.putFruit(fruit))
                    tmp.putFruit(fruit);
                break;

            case 5:
                if (!bananas.putFruit(fruit))
                    tmp.putFruit(fruit);
                break;

            default:
                tmp.putFruit(fruit);
        }
        fruit = unsorted.pickFruit();
    }
    while ((fruit = tmp.pickFruit())) {
        unsorted.putFruit(fruit);
    }
}