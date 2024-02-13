/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD07pm-tanguy.bellicha
** File description:
** Parts
*/

#ifndef PARTS_HPP_
#define PARTS_HPP_

#include <string>

class Arms {
    public:
        Arms(std::string serial = (std::string) "A-01", bool functional = true);
        bool isFunctional();
        std::string serial();
        void information();

    protected:
    private:
        std::string _serial;
        bool _functional;
};

class Legs {
    public:
        Legs(std::string serial = (std::string) "L-01", bool functional = true);
        bool isFunctional();
        std::string serial();
        void information();

    protected:
    private:
        std::string _serial;
        bool _functional;
};

class Head {
    public:
        Head(std::string serial = (std::string) "H-01", bool functional = true);
        bool isFunctional();
        std::string serial();
        void information();

    protected:
    private:
        std::string _serial;
        bool _functional;
};


#endif /* !PARTS_HPP_ */
