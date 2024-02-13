/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD09-tanguy.bellicha
** File description:
** Peasant
*/

#ifndef PEASANT_HPP_
#define PEASANT_HPP_

#include "string"
#include "ICharacter.hpp"

class Peasant : virtual public ICharacter {
    public:
        Peasant(const std::string& name, int power);
        virtual ~Peasant();
        const std::string& getName() const;
        int getPower() const;
        int getHp() const;
        bool checkIsAble(int nb_power) const;
        virtual int attack();
        virtual int special();
        virtual void rest();
        void damage(int damage);

    protected:
        const std::string _name;
        int _power;
        int _health;
};

#endif /* !PEASANT_HPP_ */
