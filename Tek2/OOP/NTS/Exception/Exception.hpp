/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <string>

namespace nts
{
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

    class FileException : public Exception
    {
    public:
        FileException(std::string const &message) : Exception(message) {};
        virtual ~FileException() {};
    };

    class ComponentNameException : public Exception
    {
    public:
        ComponentNameException(std::string const &message) : Exception(message) {};
        virtual ~ComponentNameException() {};
    };

    class ComponentTypeException : public Exception
    {
    public:
        ComponentTypeException(std::string const &message) : Exception(message) {};
        virtual ~ComponentTypeException() {};
    };

    class ComponentSharedNameException : public Exception
    {
    public:
        ComponentSharedNameException(std::string const &message) : Exception(message) {};
        virtual ~ComponentSharedNameException() {};
    };

    class PinException : public Exception
    {
    public:
        PinException(std::string const &message) : Exception(message) {};
        virtual ~PinException() {};
    };

    class ChipsetException : public Exception
    {
    public:
        ChipsetException(std::string const &message) : Exception(message) {};
        virtual ~ChipsetException() {};
    };
}

#endif /* !EXCEPTION_HPP_ */
