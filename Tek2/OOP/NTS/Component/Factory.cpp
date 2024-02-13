/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Factory
*/

#include "Exception.hpp"
#include "Factory.hpp"
#include "SpecialComponent.hpp"
#include "BasicComponent.hpp"

nts::Factory::Factory()
{
    _compo["input"] = &Factory::createInput;
    _compo["output"] = &Factory::createOutput;
    _compo["true"] = &Factory::createTrue;
    _compo["false"] = &Factory::createFalse;
    _compo["clock"] = &Factory::createClock;
    _compo["4001"] = &Factory::create4001;
    _compo["4011"] = &Factory::create4011;
    _compo["4030"] = &Factory::create4030;
    _compo["4071"] = &Factory::create4071;
    _compo["4081"] = &Factory::create4081;
    _compo["4008"] = &Factory::create4008;
    _compo["4013"] = &Factory::create4013;
    _compo["4017"] = &Factory::create4017;
    _compo["4040"] = &Factory::create4040;
    _compo["4094"] = &Factory::create4094;
    _compo["4512"] = &Factory::create4512;
    _compo["4514"] = &Factory::create4514;
    _compo["4801"] = &Factory::create4801;
    _compo["2716"] = &Factory::create2716;
}

nts::Factory::~Factory()
{
}

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type)
{
    fctPtr ptr;

    if (_compo.find(type) == _compo.end()) {
		throw nts::ComponentTypeException("Component type " + type + " is unknown");
	}
    ptr = _compo[type];
	return (this->*ptr)();
}

std::unique_ptr<nts::IComponent> nts::Factory::createInput() const
{
    return std::make_unique<Input>();
}

std::unique_ptr<nts::IComponent> nts::Factory::createOutput() const
{
    return std::make_unique<Output>();
}

std::unique_ptr<nts::IComponent> nts::Factory::createTrue() const
{
    return std::make_unique<True>();
}

std::unique_ptr<nts::IComponent> nts::Factory::createFalse() const
{
    return std::make_unique<False>();
}

std::unique_ptr<nts::IComponent> nts::Factory::createClock() const
{
    return std::make_unique<Clock>();
}

std::unique_ptr<nts::IComponent> nts::Factory::create4001() const
{
   return std::make_unique<c4001>();
}

std::unique_ptr<nts::IComponent> nts::Factory::create4011() const
{
    return std::make_unique<c4011>();
}

std::unique_ptr<nts::IComponent> nts::Factory::create4030() const
{
    return std::make_unique<c4030>();
}

std::unique_ptr<nts::IComponent> nts::Factory::create4071() const
{
    return std::make_unique<c4071>();
}

std::unique_ptr<nts::IComponent> nts::Factory::create4081() const
{
    return std::make_unique<c4081>();
}

std::unique_ptr<nts::IComponent> nts::Factory::create4008() const
{
    return std::make_unique<c4008>();
}

std::unique_ptr<nts::IComponent> nts::Factory::create4013() const
{
    return std::make_unique<c4013>();
}

std::unique_ptr<nts::IComponent> nts::Factory::create4017() const
{
    return std::make_unique<c4017>();
}

std::unique_ptr<nts::IComponent> nts::Factory::create4040() const
{
    return std::make_unique<c4040>();
}

std::unique_ptr<nts::IComponent> nts::Factory::create4094() const
{
    return std::make_unique<c4094>();
}

std::unique_ptr<nts::IComponent> nts::Factory::create4512() const
{
    return std::make_unique<c4512>();
}

std::unique_ptr<nts::IComponent> nts::Factory::create4514() const
{
    return std::make_unique<c4514>();
}

std::unique_ptr<nts::IComponent> nts::Factory::create4801() const
{
    return std::make_unique<c4801>();
}

std::unique_ptr<nts::IComponent> nts::Factory::create2716() const
{
    return std::make_unique<c2716>();
}
