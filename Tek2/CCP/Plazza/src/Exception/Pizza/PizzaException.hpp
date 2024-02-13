/*
** EPITECH PROJECT, 2022
** Project
** File description:
** PizzaException
*/

#ifndef PIZZAEXCEPTION_HPP_
#define PIZZAEXCEPTION_HPP_

#include <exception>
#include <string>

namespace exception
{
    namespace pizza
    {

        class Exception : public std::exception {
          public:
            Exception(const std::string &message) : _message(message){};
            virtual ~Exception() = default;
            const char *what() const noexcept override
            {
                return _message.c_str();
            };

          protected:
          private:
            std::string _message;
        };

        class InvalidPizzaType : public Exception {
          public:
            InvalidPizzaType(std::string const &message) : Exception(message){};
            virtual ~InvalidPizzaType(){};
        };

        class InvalidPizzaSize : public Exception {
          public:
            InvalidPizzaSize(std::string const &message) : Exception(message){};
            virtual ~InvalidPizzaSize(){};
        };

        class InvalidPizzaNumber : public Exception {
          public:
            InvalidPizzaNumber(std::string const &message) : Exception(message){};
            virtual ~InvalidPizzaNumber(){};
        };
    } // namespace pizza
} // namespace exception

#endif /* !PIZZAEXCEPTION_HPP_ */
