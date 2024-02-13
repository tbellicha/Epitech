/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD07pm-tanguy.bellicha
** File description:
** Skat
*/

#ifndef SKAT_HPP_
#define SKAT_HPP_

#include "string"

class Skat {
    public:
        Skat(const std::string &name = (std::string) "bob", int stimPaks = 15);
        ~Skat();

        int &stimPaks() ;
        const std::string &name();
        void shareStimPaks(int number, int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status();

    protected:
    private:
        std::string _name;
        int _stimPaks;
        int _stock;
};

#endif /* !SKAT_HPP_ */
