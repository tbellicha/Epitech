/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** InfoModule
*/

#ifndef INFOMODULE_HPP_
#define INFOMODULE_HPP_

#include <string>
#include "IMonitorModule.hpp"

class InfoModule : public IMonitorModule
{
    public:
        InfoModule();
        ~InfoModule();

        std::string getHostname() const;
        std::string getUsername() const;
        std::string getOperatingSystem() const;
        std::string getKernelVersion() const;
        std::string getDateTime() const;
        void setAllInfos();

    protected:
    private:
        std::string _hostname;
        std::string _username;
        std::string _operatingSystem;
        std::string _kernelVersion;
        std::string _dateTime;
};

#endif /* !INFOMODULE_HPP_ */
