/*
** EPITECH PROJECT, 2022
** Project
** File description:
** GraphicalException
*/


#ifndef GRAPHICALEXCEPTION_HPP_
#define GRAPHICALEXCEPTION_HPP_

#include <string>
#include <exception>

namespace arcade {
    namespace exception {
        namespace Graphical {

            class Exception : public std::exception
            {
            public:
                Exception(const std::string &message) : _message(message) {};
                virtual ~Exception() = default;
                const char *what() const noexcept override {return _message.c_str();};

            protected:
            private:
                std::string _message;
            };

            class GraphicalException : public Exception
            {
            public:
                GraphicalException(std::string const &message) : Exception(message) {};
                virtual ~GraphicalException() {};
            };
        }
    }
}

#endif /* !GRAPHICALEXCEPTION_HPP_ */