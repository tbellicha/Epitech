/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD10am-tanguy.bellicha
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <string>

class Fruit {
    public:
        virtual ~Fruit();

        std::string getName() const;
        int getVitamins() const;

    protected:
        std::string name;
        int _vitamins;

        Fruit(std::string name, int vitamins);
        Fruit();
    private:
};

#endif /* !FRUIT_HPP_ */
