/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD11-tanguy.bellicha
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : virtual public Toy {
    public:
        Buzz(std::string name, std::string filename = "buzz.txt");
        virtual ~Buzz();
        virtual bool speak(std::string statement);
        virtual bool speak_es(std::string statement);

    protected:
    private:
};

#endif /* !BUZZ_HPP_ */
