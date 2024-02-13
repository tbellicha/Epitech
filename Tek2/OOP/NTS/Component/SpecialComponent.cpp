/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** SpecialComponent
*/

#include "SpecialComponent.hpp"

nts::Input::Input()
{
    _state = UNDEFINED;
}


nts::Tristate nts::Input::compute(std::size_t pin)
{
    (void)pin;
    return _state;
}

nts::Output::Output()
{
    _state = UNDEFINED;
}

nts::Tristate nts::Output::compute(std::size_t pin)
{
    (void)pin;
    return _state;
}

nts::True::True()
{
    _state = UNDEFINED;
}

nts::Tristate nts::True::compute(std::size_t pin)
{
    (void)pin;
    return _state;
}

nts::False::False()
{
    _state = UNDEFINED;
}

nts::Tristate nts::False::compute(std::size_t pin)
{
    (void)pin;
    return _state;
}

nts::Clock::Clock()
{
    _state = UNDEFINED;
}

nts::Tristate nts::Clock::compute(std::size_t pin)
{
    (void)pin;
    return _state;
}