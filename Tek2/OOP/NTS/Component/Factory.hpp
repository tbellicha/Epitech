/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <map>
#include <memory>
#include <unordered_map>
#include "IComponent.hpp"

namespace nts
{
    class Factory;
    using fctPtr = std::unique_ptr<IComponent>(Factory::*)() const;
    class Factory
    {
    public:
        Factory();
        ~Factory();
        virtual std::unique_ptr<nts::IComponent> createComponent(const std::string &type);

    protected:
    private:
        std::unordered_map<std::string, fctPtr> _compo;
        std::unique_ptr<nts::IComponent> createInput() const;
        std::unique_ptr<nts::IComponent> createOutput() const;
        std::unique_ptr<nts::IComponent> createTrue() const;
        std::unique_ptr<nts::IComponent> createFalse() const;
        std::unique_ptr<nts::IComponent> createClock() const;
        std::unique_ptr<nts::IComponent> create4001() const;
        std::unique_ptr<nts::IComponent> create4011() const;
        std::unique_ptr<nts::IComponent> create4030() const;
        std::unique_ptr<nts::IComponent> create4071() const;
        std::unique_ptr<nts::IComponent> create4081() const;
        std::unique_ptr<nts::IComponent> create4008() const;
        std::unique_ptr<nts::IComponent> create4013() const;
        std::unique_ptr<nts::IComponent> create4017() const;
        std::unique_ptr<nts::IComponent> create4040() const;
        std::unique_ptr<nts::IComponent> create4094() const;
        std::unique_ptr<nts::IComponent> create4512() const;
        std::unique_ptr<nts::IComponent> create4514() const;
        std::unique_ptr<nts::IComponent> create4801() const;
        std::unique_ptr<nts::IComponent> create2716() const;
    };
}
#endif /* !FACTORY_HPP_ */
