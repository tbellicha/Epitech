/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD09-tanguy.bellicha
** File description:
** Knight
*/

#ifndef KNIGHT_HPP_
#define KNIGHT_HPP_

#include "Peasant.hpp"

class Knight : virtual public Peasant {
    public:
        Knight(const std::string& name, int power);
        virtual ~Knight();
        int attack();
        int special();
        void rest();

    protected:
    private:
};

#endif /* !KNIGHT_HPP_ */
