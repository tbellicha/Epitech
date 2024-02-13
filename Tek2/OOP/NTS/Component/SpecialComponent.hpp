/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** SpecialComponent
*/

#ifndef SPECIALCOMPONENT_HPP_
#define SPECIALCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {

class Input : public AComponent {
   public:
    Input();
    ~Input() = default;
    nts::Tristate compute(std::size_t pin = 0);

   protected:
    const std::string _value;
    nts::Tristate _state;

   private:
};

class Output : public AComponent {
   public:
    Output();
    ~Output() = default;
    nts::Tristate compute(std::size_t pin = 0);

   protected:
    const std::string _value;
    nts::Tristate _state;

   private:
};

class Clock : public AComponent {
   public:
    Clock();
    ~Clock() = default;
    nts::Tristate compute(std::size_t pin = 0);

   protected:
    const std::string _value;
    nts::Tristate _state;

   private:
};

class True : public AComponent {
   public:
    True();
    ~True() = default;
    nts::Tristate compute(std::size_t pin = 0);

   protected:
    const std::string _value;
    nts::Tristate _state;

   private:
};

class False : public AComponent {
   public:
    False();
    ~False() = default;
    nts::Tristate compute(std::size_t pin = 0);

   protected:
    const std::string _value;
    nts::Tristate _state;

   private:
};
}  // namespace nts

#endif /* !SPECIALCOMPONENT_HPP_ */
