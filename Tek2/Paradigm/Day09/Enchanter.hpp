/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD09-tanguy.bellicha
** File description:
** Enchanter
*/

#ifndef ENCHANTER_HPP_
#define ENCHANTER_HPP_

#include "Peasant.hpp"

class Enchanter : virtual public Peasant {
    public:
        Enchanter(const std::string& name, int power);
        virtual ~Enchanter();
        int attack();
        int special();
        virtual void rest();

    protected:
    private:
};

#endif /* !ENCHANTER_HPP_ */
