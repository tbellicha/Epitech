/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD09-tanguy.bellicha
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Knight.hpp"
#include "Priest.hpp"

class Paladin : virtual public Knight, virtual public Priest {
    public:
        Paladin(const std::string& name, int power);
        virtual ~Paladin();
        int attack();
        int special();
        void rest();
        void damage(int damage);

    protected:
    private:
};

#endif /* !PALADIN_HPP_ */
