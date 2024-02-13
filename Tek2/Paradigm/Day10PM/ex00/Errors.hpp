/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD10pm-tanguy.bellicha
** File description:
** Errors
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>

class NasaError : public std::exception
{
    private:
        std::string _message;
        std::string _component;

    public:
        NasaError(std::string const &message, std::string const &component = "Unknown");
        virtual ~NasaError() throw() {};

        std::string const &getComponent() const;
        const char* what() const noexcept;
};

class MissionCriticalError : public NasaError
{
    public:
        MissionCriticalError(std::string const &message, std::string const &component = "Unknown");
        virtual ~MissionCriticalError() throw() {};
};

class LifeCriticalError : public NasaError
{
    public:
        LifeCriticalError(std::string const &message, std::string const &component = "Unknown");
        virtual ~LifeCriticalError() throw() {};
};

class UserError : public NasaError
{
    public:
        UserError(std::string const &message, std::string const &component = "Unknown");
        virtual ~UserError() throw() {};
};

class CommunicationError : public NasaError
{
    public:
        CommunicationError(std::string const &message);
        virtual ~CommunicationError() throw() {};
};

#endif /* !ERRORS_HPP_ */
