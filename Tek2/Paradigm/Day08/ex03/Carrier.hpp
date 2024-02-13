/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD08-tanguy.bellicha
** File description:
** Carrier
*/

#ifndef CARRIER_HPP_
#define CARRIER_HPP_

#include "string"
#include "Droid.hpp"

class Carrier {
    public:
        Carrier(std::string id);
        ~Carrier();

        // void setId(std::string id);
        // void setEnergy(size_t energy);
        // void setSpeed(size_t speed);
        // void setDroids(Droid* droids[5]);

        // std::string getId();
        // size_t getEnergy();
        size_t getSpeed();
        // Droid* getDroids();
        Carrier& operator<<(Droid* droid);
        Carrier& operator>>(Droid* droid);
        void printCarrier() const;

    protected:
    private:
        std::string _id;
        size_t _energy;
        const size_t _attack;
        const size_t _toughness;
        size_t _speed;
        Droid** _droids;

};

#endif /* !CARRIER_HPP_ */
