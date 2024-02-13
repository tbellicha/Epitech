/*
** EPITECH PROJECT, 2022
** Project
** File description:
** ArgsException
*/

#ifndef ARGSEXCEPTION_HPP_
#define ARGSEXCEPTION_HPP_

#include <exception>
#include <string>

namespace exception
{
    namespace args
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

        class NumberOfArgs : public Exception {
          public:
            NumberOfArgs(std::string const &message) : Exception(message){};
            virtual ~NumberOfArgs(){};
        };

        class MultiplierArg : public Exception {
          public:
            MultiplierArg(std::string const &message) : Exception(message){};
            virtual ~MultiplierArg(){};
        };

        class NumberOfCooksArg : public Exception {
          public:
            NumberOfCooksArg(std::string const &message) : Exception(message){};
            virtual ~NumberOfCooksArg(){};
        };

        class TimeArg : public Exception {
          public:
            TimeArg(std::string const &message) : Exception(message){};
            virtual ~TimeArg(){};
        };
    } // namespace args
} // namespace exception

#endif /* !ARGSEXCEPTION_HPP_ */
