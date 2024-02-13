/*
** EPITECH PROJECT, 2022
** Project
** File description:
** ShellException
*/

#ifndef SHELLEXCEPTION_HPP_
#define SHELLEXCEPTION_HPP_

#include <exception>
#include <string>

namespace exception
{
    namespace shell
    {

        class Exception : public std::exception {
          public:
            Exception(const std::string &message) : _message(message){};
            virtual ~Exception() = default;
            const char *what() const noexcept override
            {
                return _message.c_str();
            };

          private:
            std::string _message;
        };

        class InvalidNbrArgumentInOrder : public Exception {
          public:
            InvalidNbrArgumentInOrder(std::string const &message) : Exception(message){};
            virtual ~InvalidNbrArgumentInOrder(){};
        };

        class InvalidNbrPizzaInput : public Exception {
          public:
            InvalidNbrPizzaInput(std::string const &message) : Exception(message){};
            virtual ~InvalidNbrPizzaInput(){};
        };
    } // namespace shell
} // namespace exception

#endif /* !SHELLEXCEPTION_HPP_ */
