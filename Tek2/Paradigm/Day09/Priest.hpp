/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD09-tanguy.bellicha
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Enchanter.hpp"

class Priest : virtual public Enchanter {
    public:
        Priest(const std::string& name, int power);
        virtual ~Priest();
        void rest();

    protected:
    private:
};

#endif /* !PRIEST_HPP_ */
