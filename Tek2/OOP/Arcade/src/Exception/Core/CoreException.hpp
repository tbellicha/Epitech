/*
** EPITECH PROJECT, 2022
** Project
** File description:
** CoreException
*/

#ifndef COREEXCEPTION_HPP_
#define COREEXCEPTION_HPP_

#include <string>
#include <exception>

namespace arcade {
    namespace exception {
        namespace core {

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

            class LibraryLoading : public Exception
            {
            public:
                LibraryLoading(std::string const &message) : Exception(message) {};
                virtual ~LibraryLoading() {};
            };

            class InvalidArguments : public Exception
            {
            public:
                InvalidArguments(std::string const &message) : Exception(message) {};
                virtual ~InvalidArguments() {};
            };
        }
    }
}

#endif /* !COREEXCEPTION_HPP_ */
