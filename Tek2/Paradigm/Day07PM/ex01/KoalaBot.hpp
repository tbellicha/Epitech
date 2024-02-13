/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD07pm-tanguy.bellicha
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_

#include "Parts.hpp"

class KoalaBot {
    public:
        KoalaBot(std::string name = (std::string) "Bob-01");
        void setParts(Arms &arms);
        void setParts(Legs &legs);
        void setParts(Head &head);
        void swapParts(Arms &arms);
        void swapParts(Legs &legs);
        void swapParts(Head &head);

        void informations() const;
        bool status() const;

    protected:
    private:
        std::string _name;
        Arms _arms;
        Legs _legs;
        Head _head;
};

#endif /* !KOALABOT_HPP_ */
