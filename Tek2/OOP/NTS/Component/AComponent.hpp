/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include "IComponent.hpp"

namespace nts
{
    class AComponent : public IComponent
    {
    public:
        AComponent();
        ~AComponent();
        virtual nts::Tristate compute(std::size_t pin = 0) = 0;
        void simulate(std::size_t tick);
        void setLink(std::size_t pin, nts ::IComponent &other, std::size_t otherPin);
        void dump() const;

    protected:
    private:
    };
}

#endif /* !ACOMPONENT_HPP_ */
