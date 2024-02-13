/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** InfoModule
*/

#include "InfoModule.hpp"
#include <sys/utsname.h>
#include <iostream>
#include <thread>
#include <time.h>

InfoModule::InfoModule()
{
    this->setAllInfos();
}

InfoModule::~InfoModule()
{
}



std::string InfoModule::getHostname() const
{
    return this->_hostname;
}

std::string InfoModule::getUsername() const
{
    return this->_username;
}

std::string InfoModule::getOperatingSystem() const
{
    return this->_operatingSystem;
}

std::string InfoModule::getKernelVersion() const
{
    return this->_kernelVersion;
}

std::string InfoModule::getDateTime() const
{
    return this->_dateTime;
}

void InfoModule::setAllInfos()
{
    struct utsname buff;
    uname(&buff);
    std::string versionString(buff.version);
    std::time_t t = std::time(0);

    this->_dateTime = ctime(&t);
    this->_hostname = buff.nodename;
    this->_kernelVersion = buff.release;
    this->_operatingSystem = buff.sysname;
    this->_username = getenv("USER");
    this->title = "Info Module";
}