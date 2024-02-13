/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** BasicComponent
*/

#ifndef BASICCOMPONENT_HPP_
#define BASICCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {

class c4001 : public AComponent {
   public:
    c4001();
    ~c4001() = default;
    nts::Tristate compute(std::size_t pin = 0);

   protected:
    const std::string _value;
    nts::Tristate _state;

   private:
};
class c4011 : public AComponent {
   public:
    c4011();
    ~c4011() = default;
    nts::Tristate compute(std::size_t pin = 0);

   protected:
    const std::string _value;
    nts::Tristate _state;

   private:
};

class c4030 : public AComponent {
   public:
    c4030();
    ~c4030() = default;
    nts::Tristate compute(std::size_t pin = 0);

   protected:
    const std::string _value;
    nts::Tristate _state;

   private:
};

class c4071 : public AComponent {
   public:
    c4071();
    ~c4071() = default;
    nts::Tristate compute(std::size_t pin = 0);

   protected:
    const std::string _value;
    nts::Tristate _state;

   private:
};

class c4081 : public AComponent {
   public:
    c4081();
    ~c4081() = default;
    nts::Tristate compute(std::size_t pin = 0);

   protected:
    const std::string _value;
    nts::Tristate _state;

   private:
};

class c4008 : public AComponent {
   public:
    c4008();
    ~c4008() = default;
    nts::Tristate compute(std::size_t pin = 0);

   protected:
    const std::string _value;
    nts::Tristate _state;

   private:
};

class c4013 : public AComponent {
   public:
    c4013();
    ~c4013() = default;
    nts::Tristate compute(std::size_t pin = 0);

   protected:
    const std::string _value;
    nts::Tristate _state;

   private:
};

class c4017 : public AComponent {
   public:
    c4017();
    ~c4017() = default;
    nts::Tristate compute(std::size_t pin = 0);

   protected:
    const std::string _value;
    nts::Tristate _state;

   private:
};

class c4040 : public AComponent {
   public:
    c4040();
    ~c4040() = default;
    nts::Tristate compute(std::size_t pin = 0);

   protected:
    const std::string _value;
    nts::Tristate _state;

   private:
};

class c4094 : public AComponent {
   public:
    c4094();
    ~c4094() = default;
    nts::Tristate compute(std::size_t pin = 0);

   protected:
    const std::string _value;
    nts::Tristate _state;

   private:
};

class c4512 : public AComponent {
   public:
    c4512();
    ~c4512() = default;
    nts::Tristate compute(std::size_t pin = 0);

   protected:
    const std::string _value;
    nts::Tristate _state;

   private:
};

class c4514 : public AComponent {
   public:
    c4514();
    ~c4514() = default;
    nts::Tristate compute(std::size_t pin = 0);

   protected:
    const std::string _value;
    nts::Tristate _state;

   private:
};

class c4801 : public AComponent {
   public:
    c4801();
    ~c4801() = default;
    nts::Tristate compute(std::size_t pin = 0);

   protected:
    const std::string _value;
    nts::Tristate _state;

   private:
};

class c2716 : public AComponent {
   public:
    c2716();
    ~c2716() = default;
    nts::Tristate compute(std::size_t pin = 0);

   protected:
    const std::string _value;
    nts::Tristate _state;

   private:
};
}  // namespace nts

#endif /* !BASICCOMPONENT_HPP_ */
