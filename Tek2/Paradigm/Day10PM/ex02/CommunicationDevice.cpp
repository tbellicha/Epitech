#include <iostream>
#include <stdexcept>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(std::istream &input, std::ostream &output)
    try : _api(input, output)
    {
    } catch (std::exception const& error) {
        throw CommunicationError((std::string) "Error: " + error.what());
}

CommunicationDevice::~CommunicationDevice()
{
}

void    CommunicationDevice::startMission(std::string const &missionName, std::string *users, size_t nbUsers)
{
    try {
        for (size_t i = 0; i < nbUsers; ++i)
            this->_api.addUser(users[i]);
        this->_api.startMission(missionName);
    } catch (std::logic_error const& error) {
        throw CommunicationError((std::string) "LogicError: " + error.what());
    } catch (std::runtime_error const& error) {
        throw CommunicationError((std::string) "RuntimeError: " + error.what());
    } catch (std::exception const& error) {
        throw CommunicationError((std::string) "Error: " + error.what());
    }
}

void    CommunicationDevice::send(std::string const &user, std::string const &message) const
{
    try {
        this->_api.sendMessage(user, message);
    } catch (std::exception const& error) {
        std::cerr << error.what() << std::endl;
    }
}

void    CommunicationDevice::receive(std::string const &user, std::string &message) const
{
    try {
        this->_api.receiveMessage(user, message);
    } catch (std::exception const& error) {
        std::cerr << error.what() << std::endl;
        std::cerr << "INVALID MESSAGE";
    }
}
