/*
** EPITECH PROJECT, 2022
** RUSH3
** File description:
** AllMonitors
*/

#include "AllMonitors.hpp"
#include <thread>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <filesystem>
#include <sys/sysinfo.h>

AllMonitors::AllMonitors()
{
    this->_nbCore = std::thread::hardware_concurrency();
    this->_coreInfo = new CoreInfo[_nbCore];
    this->title = "Core monitor";
}

AllMonitors::~AllMonitors()
{
}

size_t AllMonitors::getNbCore() const
{
    return this->_nbCore;
}

double AllMonitors::getPercentageUse() const
{
    std::string line;
    std::ifstream finfo("/proc/loadavg");
    if (!finfo.is_open())
        return (-1);
    getline(finfo, line);
    std::stringstream str(line);
    std::string info;
    if (getline(str, info, ' '))
        return (stod(info) * 100 / this->_nbCore);
    return (-1);
}

void AllMonitors::setAllInfo()
{
    size_t idx = 0;
    size_t tmp = 0;
    std::string line;
    std::ifstream finfo("/proc/cpuinfo");
    while (getline(finfo,line) && finfo.is_open() && idx < this->_nbCore) {
        std::stringstream str(line);
        std::string itype;
        std::string model;
        std::string freq;
        if (getline(str, itype, ':') && getline(str, model)) {
            if (itype.substr(0,10) == "model name") {
                this->_coreInfo[idx]._model = model;
                tmp++;
            }
            if (itype.substr(0,7) == "cpu MHz") {
                this->_coreInfo[idx]._frequency = stod(model);
                tmp++;
            }
            if (tmp == 2) {
                this->_coreInfo[idx]._temperature = getTemperature();
                idx++;
                tmp = 0;
            }
        }
    }
    this->getCorePercentInfo();
    this->initRam();
    this->initNetwork();
    this->initDiskSpace();
}

void AllMonitors::printAllInfo()
{
    for (size_t i = 0; i < _nbCore; i++) {
        std::cout << "percentage : " << this->_coreInfo[i]._percentage << std::endl;
        std::cout << "model : " << this->_coreInfo[i]._model << std::endl;
        std::cout << "frequency : " << this->_coreInfo[i]._frequency << std::endl;
        std::cout << "temperature : " << this->_coreInfo[i]._temperature << std::endl;
        std::cout << std::endl;
    }
}

double AllMonitors::getTemperature() const
{
    std::string line;
    double temp[this->_nbCore];
    double average_temp = 0;
    int i_temps = 0;
    system("sensors > tmp");
    std::ifstream finfo("./tmp");
    if (!finfo.is_open())
        return (-1);
    while (getline(finfo, line)) {
        std::stringstream str(line);
        std::string itype;
        std::string info;
        if (getline(str, itype, ':') && getline(str, info) && itype.substr(0, 4) == "Core") {
            temp[i_temps] = stoi(info);
            average_temp += temp[i_temps];
        }
    }
    return (average_temp / this->_nbCore);
}

std::string *split(std::string str, char delimiter) {
    std::string *internal = new std::string[11];
    std::stringstream ss(str);
    std::string tok;
    int i = 0;

    while(i < 11) {
        getline(ss, tok, delimiter);
        internal[i] = tok;
        i++;
    }
    return internal;
}

double getTotalCPU(std::string line)
{
    std::string *lineParsed = split(line, ' ');
    double val = 0;

    for (long unsigned int i = 2; i < 8; i++) {
        val += std::stod(lineParsed[i]);
    }
    delete[] lineParsed;
    return val;
}

double getIdleCPU(std::string line)
{
    std::string *lineParsed = split(line, ' ');
    return stod(lineParsed[3]);
}

void AllMonitors::getCorePercentInfo()
{
    size_t idx = 0;
    std::string line;
    std::ifstream finfo("/proc/stat", std::ios::in);
    double tmp1[_nbCore];
    double beg1[_nbCore];
    while (getline(finfo,line) && finfo.is_open() && idx <= this->_nbCore) {
        std::string sub;
        if (sub.substr(0, 3) != "cpu\t") {
            tmp1[idx - 1] = getTotalCPU(line);
            beg1[idx - 1] = getIdleCPU(line);
            idx++;
        }
    }
    this->_allCoreUsage = (beg1[-1] * 100) / tmp1[-1];
    for (size_t i = 0; i < _nbCore; i++)
        this->_coreInfo[i]._percentage = (beg1[i] * 100) / tmp1[i];
}

void AllMonitors::initRam()
{
    struct sysinfo sys;
    short status = sysinfo(&sys);
    if (status < 0)
        return;
    float total = (float)sys.totalram / (1024 * 1024 * 1024);
    float available = (float)sys.freeram / (1024 * 1024 * 1024);
    float used = total - available;
    this->_ramTotal = total;
    this->_ramUsed = used;
}

void AllMonitors::initNetwork()
{
    std::string src = "/proc/net/dev";
    std::string	line;
    std::ifstream file(src.c_str(), std::ios::in);
    int	max = 0;
    int	a = 0;
    int	i = 0;
    std::string	temp;

    while (std::getline(file, line))
    {
        if ((a = line.find(":")) != -1)
        {
            a++;
            while (line[a] == ' ')
                a++;
            while (line[a] != ' ')
            {
                temp += line[a];
                a++;
            }
            if (std::stoi(temp) > max)
            {
                this->_network.setUp(stod(temp) / 100000000);
                temp.erase();
                while (i != 7)
                {
                    while (line[a] == ' ')
                        a++;
                    while (line[a] != ' ')
                        a++;
                    i++;
                }
                i = 0;
                while (line[a] == ' ')
                    a++;
                while (line[a] != ' ')
                {
                    temp += line[a];
                    a++;
                }
                this->_network.setDown(std::stod(temp) / 100000000);
            }
        }
        temp.erase();
    }
    file.close();
}

double AllMonitors::getRamUsed() const
{
    return this->_ramUsed;
}

double AllMonitors::getRamTotal() const
{
    return this->_ramTotal;
}

double AllMonitors::getDiskFree() const
{
    return this->_memoFree;
}

double AllMonitors::getDiskAvail() const
{
    return this->_memoAvail;
}

const CoreInfo* AllMonitors::getCoreInfo() const
{
    return this->_coreInfo;
}
void AllMonitors::initDiskSpace()
{
    std::filesystem::space_info tmp = std::filesystem::space("/");
    this->_memoFree = tmp.free / 1000000000.f;
    this->_memoAvail = tmp.available / 1000000000.f;
}

NetworkModule AllMonitors::getNetwork() const
{
    return this->_network;
}
